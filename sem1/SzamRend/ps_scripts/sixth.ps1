[int32]$a = Read-Host "a = "
[int32]$b = Read-Host "b = "

function Pyth {
    param([int32]$a, [int32]$b)
    return [math]::sqrt([math]::Pow($a, 2) + [math]::Pow($b, 2))
}

$c = Pyth $a $b
Write-Host "c: $c"