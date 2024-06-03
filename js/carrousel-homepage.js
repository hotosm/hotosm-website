  document.addEventListener('DOMContentLoaded', () => {
      const links = document.querySelectorAll('.slider-nav a');
      const slider = document.querySelector('.slider');
      const slides = document.querySelectorAll('.slide');
      const leftArrow = document.querySelector('.arrow.left');
      const rightArrow = document.querySelector('.arrow.right');
      let currentIndex = 0;
      let autoSlideInterval;
  
      // Function to navigate to a specific slide
      function navigateToSlide(index) {
        if (index >= 0 && index < slides.length) {
          slider.scrollTo({
            left: slides[index].offsetLeft,
            behavior: 'smooth'
          });
  
          // Update active class on navigation dots
          links.forEach(link => link.classList.remove('active'));
          links[index].classList.add('active');
        }
      }
  
      // Set up click event for navigation links
      links.forEach(link => {
        link.addEventListener('click', (event) => {
          event.preventDefault();
          clearInterval(autoSlideInterval);
          currentIndex = parseInt(link.getAttribute('data-slide'));
          navigateToSlide(currentIndex);
          startAutoSlide(); // Restart auto-slide after manual navigation
        });
      });
  
      // Auto-slide functionality
      function startAutoSlide() {
        autoSlideInterval = setInterval(() => {
          currentIndex = (currentIndex + 1) % slides.length;
          navigateToSlide(currentIndex);
        }, 5000);
      }
  
      // Arrow navigation functionality
      if (leftArrow) {
        leftArrow.addEventListener('click', () => {
          clearInterval(autoSlideInterval);
          currentIndex = (currentIndex - 1 + slides.length) % slides.length;
          navigateToSlide(currentIndex);
          startAutoSlide(); // Restart auto-slide after manual navigation
        });
      }
  
      if (rightArrow) {
        rightArrow.addEventListener('click', () => {
          clearInterval(autoSlideInterval);
          currentIndex = (currentIndex + 1) % slides.length;
          navigateToSlide(currentIndex);
          startAutoSlide(); // Restart auto-slide after manual navigation
        });
      }
  
      // Initialize the slider
      if (links.length > 0) {
        links[0].classList.add('active');
        startAutoSlide();
      }
    });