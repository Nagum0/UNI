param(
    [string]$fileName
)

gcc .\$fileName.c
.\a
echo $?