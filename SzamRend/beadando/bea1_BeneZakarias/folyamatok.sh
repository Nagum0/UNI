# Bene Zakarias
# UAUYQF
# uauyqf@INF.ELTE.HU

#!/bin/bash

# Készítsen shell szkriptet folyamatok.sh néven, amely egy számítógép képzelt futó folyamatait kezeli. A számítógép bekapcsolásakor néhány folyamat automatikusan elindul 
# (ezeket egy indulo.dat fájlban tároljuk). A szkriptünkkel az aktuálisan futó folyamatokat tudjuk kezelni különböző kapcsolókkal.
# Az –start kapcsolóval indítsunk egy új folyamatot megadva az indítandó alkalmazás nevét - a szkript rendeljen hozzá egy PID számot is egy „S” státusszal együtt 
# és az így keletkezett új folyamattal bővítse az aktuálisan futó folyamatokat tartalmazó fájlt (aktualis.dat).
# A –stop kapcsolóval a PID számot megadva terminálja a folyamatot (a státusz a fájlban változzon S-ről T-re).
# A –kill kapcsolóra és a PID számra töröljük a fájlből a folyamatot!
# A –lista kapcsolóval listázzuk ki a folyamatokat.

# Megkeresi a legnagyobb pid szamot az aktualis.dat fileban es hozzaad egyet.
genPid() {
    local filePath=$1
    local pids=$(cut -d ' ' -f 2 $filePath)
    local maxPid=0

    for i in $pids 
    do
        if [ $maxPid -lt $i ] 
        then
            maxPid=$i
        fi
    done

    let maxPid+=1

    echo $maxPid
}

# Atirja az S-et az aktualis.dat fileban T-re, ha letezik olyan PID szam.
stopFolyamat() {
    local filePath=$1
    local pid=$2

    if grep -q "$pid S" $filePath
    then
        # Ez a sor a `sed` hasznalataval atirja a $pid S-et $pid T-re.
        sed -i "s/$pid S/$pid T/" $filePath
    else
        echo "PID: $pid not found."
    fi
}

killFolyamat() {
    local filePath=$1
    local pid=$2

    if grep -q "$pid" $filePath
    then
        sed -i "/$pid/d" $filePath
    else
        echo "PID: $pid not found."
    fi
}

# aktualis.dat filePath
filePath="aktualis.dat"

# Ellenőrizzük, hogy létezik e az aktualis.dat file.
# Ha nem, akkor létrehozza és beleírja az indulo.dat adatait.
if [ ! -e $filePath ]
then
    cat indulo.dat >> $filePath
fi

if [ $# -eq 2 ] 
then
    # -start
    if [ $1 == "-start" ] 
    then
        name=$2
        pid=$(genPid $filePath)
        status="S"

        echo "$name $pid $status" >> $filePath
    # -stop
    elif [ $1 == "-stop" ] 
    then
        stopFolyamat $filePath $2
    # -kill
    elif [ $1 == "-kill" ]
    then
        killFolyamat $filePath $2
    else
        echo "Ismeretlen kapcsolo: $1"
    fi
elif [ $1 == "-lista" ]
then
    cat $filePath
else
    echo "Ismeretlen kapcsolo: $1"
fi