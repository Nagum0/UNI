# Bene Zakarias
# UAUYQF
# uauyqf@INF.ELTE.HU

# Készítsen shell szkriptet folyamatok.sh néven, amely egy számítógép képzelt futó folyamatait kezeli. A számítógép bekapcsolásakor néhány folyamat automatikusan elindul 
# (ezeket egy indulo.dat fájlban tároljuk). A szkriptünkkel az aktuálisan futó folyamatokat tudjuk kezelni különböző kapcsolókkal.
# Az –start kapcsolóval indítsunk egy új folyamatot megadva az indítandó alkalmazás nevét - a szkript rendeljen hozzá egy PID számot is egy „S” státusszal együtt 
# és az így keletkezett új folyamattal bővítse az aktuálisan futó folyamatokat tartalmazó fájlt (aktualis.dat).
# A –stop kapcsolóval a PID számot megadva terminálja a folyamatot (a státusz a fájlban változzon S-ről T-re).
# A –kill kapcsolóra és a PID számra töröljük a fájlből a folyamatot!
# A –lista kapcsolóval listázzuk ki a folyamatokat.

# Megkeresi a legnagyobb pid szamot az aktualis.dat fileban es hozzaad egyet.
function GenPid {
    param([String]$FilePath)

    $Pids = Get-Content $FilePath | ForEach-Object { ($_ -split ' ')[1] }
    [int32]$MaxPid = 0

    foreach ($i in $Pids) {
        if ($MaxPid -lt $i) {
            $MaxPid = $i
        }
    }

    $MaxPid++
    $MaxPid
}

# Atirja az S-et az aktualis.dat fileban T-re, ha letezik olyan PID szam.
function StopFolyamat {
    param([String]$FilePath, [int32]$proId)

    if (Get-Content $FilePath | Select-String "$proId S") {
        (Get-Content $FilePath) -replace "$proId S", "$proId T" | Set-Content $FilePath
    } else {
        Write-Host "PID: $proId not found."
    }
}

# Folyamat leallitasa.
function KillFolyamat {
    param([String]$FilePath, [int32]$proId)

    if (Get-Content $FilePath | Select-String "$proId") {
        (Get-Content $FilePath) -notmatch "$proId" | Set-Content $FilePath
    } else {
        Write-Host "PID: $proId not found."
    }
}

# aktualis.dat filePath
$FilePath = "aktualis.dat"

# Ellenőrizzük, hogy létezik e az aktualis.dat file.
# Ha nem, akkor létrehozza és beleírja az indulo.dat adatait.
if (-not (Test-Path $FilePath)) {
    Get-Content "indulo.dat" | Out-File -FilePath $FilePath -Append
}

if ($args.Count -eq 2) {
    # -start
    if ($args[0] -eq "-start") {
        $Name = $args[1]
        $proId = GenPid -FilePath $FilePath
        $Status = "S"

        "$Name $proId $Status" | Out-File -FilePath $FilePath -Append
    }
    # -stop
    elseif ($args[0] -eq "-stop") {
        StopFolyamat -FilePath $FilePath $args[1]
    }
    # -kill
    elseif ($args[0] -eq "-kill") {
        KillFolyamat -FilePath $FilePath $args[1]
    }
    else {
        Write-Host "Ismeretlen kapcsolo: $($args[0])"
    }
}
elseif ($args[0] -eq "-lista") {
    Get-Content $FilePath
}
else {
    Write-Host "Ismeretlen kapcsolo: $($args[0])"
}