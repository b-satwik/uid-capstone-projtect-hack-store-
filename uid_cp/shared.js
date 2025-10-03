let cartItems = JSON.parse(localStorage.getItem("cart")) || [];
let wishlistItems = JSON.parse(localStorage.getItem("wishlist")) || [];

function updateCounters() {
  document.getElementById("cart-count").innerText = cartItems.length;
  document.getElementById("wishlist-count").innerText = wishlistItems.length;
}

// Run when page loads
document.addEventListener("DOMContentLoaded", updateCounters);

// Example usage
function addToCart(item) {
  cartItems.push(item);
  localStorage.setItem("cart", JSON.stringify(cartItems));
  updateCounters();
}

function addToWishlist(item) {
  wishlistItems.push(item);
  localStorage.setItem("wishlist", JSON.stringify(wishlistItems));
  updateCounters();
}

