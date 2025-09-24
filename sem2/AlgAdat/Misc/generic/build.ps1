param(
    [string]$run_type
)

$file = "main"
gcc .\$file.c

.\a
echo $?