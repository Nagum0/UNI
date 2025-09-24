$height = Read-Host "Enter the height of the triangle:"

for ($i = 1; $i -le $height; $i++) {
    $spaces = " " * ($height - $i)
    $stars = "*" * $i
    Write-Host "$spaces$stars"
}