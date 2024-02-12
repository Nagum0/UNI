function DrawRect {
    param([int32]$a = 5, [int32]$b = 5)

    for ($i = 0; $i -lt $a; $i++) {
        for ($j = 0; $j -lt $b; $j++) {
            Write-Host -NoNewLine "#"
        }
        Write-Host
    }
}

function GetArea {
    param([int32]$a = 5, [int32]$b = 5)
    Write-Host "$($a * $b)"
}

if (-not ($($args.Length) -eq 2)) {
    [int32]$a = Read-Host "a"
    [int32]$b = Read-Host "b"

    DrawRect $a $b
    GetArea $a $b
}
else {
    [int32]$arg1 = $args[0]
    [int32]$arg2 = $args[1]
    
    DrawRect $arg1 $arg2
    GetArea $arg1 $arg2
}