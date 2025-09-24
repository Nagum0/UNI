[int32] $age = Read-Host "Age: "

if ($age -eq 19) {
    Write-Host "Epic <devil emoji>!"
}
elseif ($age -lt 18) {
    Write-Host "Lil kid..."
}
else {
    Write-Host ("Old fuck...")
}