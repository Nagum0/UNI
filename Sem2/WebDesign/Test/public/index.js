function setCount(count, val) {
    count.innerHTML = val
}

function setImage(img, imgState) {
    if (imgState) {
        img.src = "imgs/lac.png"
    }
    else {
        img.src = "imgs/min.png" 
    }
}

const mainBtn = document.getElementById("mainBtn")
const counterText = document.getElementById("counterText")
const resetBtn = document.getElementById("resetBtn")

let counter = 0;

mainBtn.addEventListener("click", () => {
    counter++
    setCount(counterText, counter)
})

resetBtn.addEventListener("click", () => {
    setCount(counterText, 0)
    counter = 0
})

const imgBtn = document.getElementById("imgBtn")
const img = document.getElementById("img")

let imgSetting = false

imgBtn.addEventListener("click", () => {
    imgSetting = !imgSetting
    setImage(img, imgSetting)
})