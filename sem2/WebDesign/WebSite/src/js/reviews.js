const loadMoreBtn = document.getElementById("loadMoreBtn");
const hiddenReview = document.getElementById("hiddenReview");

loadMoreBtn.addEventListener("click", () => {
    hiddenReview.classList.remove("hidden");
});