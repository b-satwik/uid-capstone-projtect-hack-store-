// Categories dropdown
document.addEventListener('DOMContentLoaded', () => {
  const dropBtn = document.querySelector('.dropbtn');
  const dropdown = document.querySelector('.dropdown');

  if(dropBtn && dropdown){
    dropBtn.addEventListener('click', () => {
      dropdown.classList.toggle('show');
    });

    window.addEventListener('click', (e) => {
      if (!dropdown.contains(e.target)) {
        dropdown.classList.remove('show');
      }
    });
  }
});
