param(
    [string]$run_type
)

if ($run_type -eq "test") {
    gcc .\src\test.c .\src\m_str\m_str.c
}
else {
    gcc .\src\main.c .\src\m_str\m_str.c
}

.\a
echo $?