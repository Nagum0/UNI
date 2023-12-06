$h = Read-Host "h"

for ($i = 0; $i -lt $h; $i++) {
    $starsLeft = "*" * $i
    $paddedStarsLeft = $starsLeft.PadLeft($h)

    $starsRight = "*" * $i
    $paddedStarsRight = $starsRight.PadRight($h + 10)

    $combinedStars = $paddedStarsLeft + $paddedStarsRight
    Write-Host $combinedStars
}
