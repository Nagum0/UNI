param(
    [string]$run_type
)

$file = "main"

if ($run_type -eq "test") {
    $file = "test"
}

gcc .\src\$file.c .\src\m_str\m_str.c
.\a
echo $?