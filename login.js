// Simple client-side login + captcha demo
// NOTE: This is intentionally front-end only for a pentest/lab environment.
// Real apps must validate credentials & captcha server-side.

(() => {
  const canvas = document.getElementById('captcha-canvas');
  const reloadBtn = document.getElementById('reload-captcha');
  const form = document.getElementById('login-form');
  const msg = document.getElementById('message');

  // Demo user store
  const USERS = [
    { username: 'redeye', password: 'redeye123' },
    { username: 'admin', password: 'password' }
  ];

  // create random captcha string (letters + digits)
  function randCaptcha(len = 6) {
    const chars = 'ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnpqrstuvwxyz23456789'; // avoid ambiguous chars
    let s = '';
    for (let i = 0; i < len; i++) s += chars.charAt(Math.floor(Math.random() * chars.length));
    return s;
  }

  // render captcha to canvas with noise/lines
  function renderCaptcha(text) {
    const ctx = canvas.getContext('2d');
    const w = canvas.width, h = canvas.height;
    // white background for readability
    ctx.fillStyle = '#ffffff';
    ctx.fillRect(0, 0, w, h);

    // draw interference lines
    for (let i = 0; i < 6; i++) {
      ctx.strokeStyle = `rgba(${Math.floor(Math.random()*120)}, ${Math.floor(Math.random()*120)}, ${Math.floor(Math.random()*120)}, 0.25)`;
      ctx.beginPath();
      ctx.moveTo(Math.random()*w, Math.random()*h);
      ctx.lineTo(Math.random()*w, Math.random()*h);
      ctx.stroke();
    }

    // draw text in varied styles
    const xGap = Math.floor(w / (text.length + 1));
    for (let i = 0; i < text.length; i++) {
      const ch = text[i];
      const fontSize = 20 + Math.floor(Math.random() * 10);
      ctx.font = `${fontSize}px sans-serif`;
      ctx.fillStyle = `rgb(${20+Math.floor(Math.random()*120)}, ${20+Math.floor(Math.random()*120)}, ${20+Math.floor(Math.random()*120)})`;
      const angle = (Math.random() - 0.5) * 0.6; // rotate
      ctx.save();
      const x = xGap * (i + 0.6);
      const y = h/2 + (Math.random() - 0.5) * 10 + fontSize/3;
      ctx.translate(x, y);
      ctx.rotate(angle);
      ctx.fillText(ch, 0, 0);
      ctx.restore();
    }

    // small dots noise
    for (let i = 0; i < 40; i++) {
      ctx.fillStyle = `rgba(0,0,0,${Math.random()*0.2})`;
      ctx.fillRect(Math.random()*w, Math.random()*h, 1, 1);
    }
  }

  // store current captcha in-memory
  let currentCaptcha = '';

  function newCaptcha() {
    currentCaptcha = randCaptcha(6);
    renderCaptcha(currentCaptcha);
  }

  // initial captcha
  newCaptcha();

  // reload on button
  reloadBtn.addEventListener('click', (e) => { e.preventDefault(); newCaptcha(); });

  // simple validation helpers
  function findUser(u,p) {
    return USERS.some(acc => acc.username === u && acc.password === p);
  }

  form.addEventListener('submit', (e) => {
    e.preventDefault();
    const u = form.username.value.trim();
    const p = form.password.value;
    const c = form.captcha.value.trim();

    msg.textContent = '';
    msg.style.color = '';

    if (!u || !p || !c) {
      msg.textContent = 'Please fill all fields.';
      msg.style.color = 'orange';
      return;
    }

    if (c.toLowerCase() !== currentCaptcha.toLowerCase()) {
      msg.textContent = 'CAPTCHA does not match. Try again.';
      msg.style.color = 'crimson';
      newCaptcha();
      form.captcha.value = '';
      return;
    }

    // Credentials check (demo)
    if (!findUser(u,p)) {
      msg.textContent = 'Invalid username or password.';
      msg.style.color = 'crimson';
      // refresh captcha on failure to simulate common site behavior
      newCaptcha();
      form.captcha.value = '';
      return;
    }

    // success: redirect to uid_cp/index.html (in uid_cp folder)
    msg.textContent = 'Login successful — redirecting...';
    msg.style.color = 'lightgreen';

    // Short delay for UX then redirect
    setTimeout(() => {
      // For lab use: you can set a flag in sessionStorage to indicate logged-in state
      sessionStorage.setItem('hackstore_logged_in', JSON.stringify({ user: u, ts: Date.now() }));
      // redirect to the index that lives inside uid_cp
      window.location.href = 'uid_cp/index.html';
    }, 700);
  });

  // Optional: allow Enter on captcha to submit from keyboard (default works)
})();
