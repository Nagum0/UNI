function Multiply {
    param([int32]$a, [int32]$b)
    return $a * $b
}

$product = Multiply 2 3
Write-Host "Product $product"