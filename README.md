# Hack Store — UID Capstone Project

**Repository:** `uid-capstone-projtect-hack-store-`  
**Author / Maintainer:** Bala Satwik

> ⚠️ **Ethical use only.** This project is for education, defensive research, and portfolio purposes. Do **not** use the materials for illegal activity. Always obtain explicit permission before testing any systems you do not own.

---

## Project summary
Hack Store is a frontend e-commerce demo built as a UID capstone project to showcase gated distribution of pentesting tools and learning resources. The UI demonstrates a UID-based client-side login flow, gated product downloads (unlock code or authenticated session), and the use of external cloud drives (Mega / Google Drive) for hosting large assets. Binaries are stored off-repo and referenced by share links.

---

## Key features
- Simple frontend (HTML / CSS / JavaScript) product catalog and product detail pages.  
- UID-driven login/session model (localStorage demo) to gate downloads.  
- Product pages reveal external download links only after UID / unlock code verification.  
- Cart support with a demo coupon code for discounts.  
- External storage integration: Mega.nz / Google Drive links for large files (do **not** commit binaries).  
- Wiring flow: `main.html → login.html → index.html → product.html → download`.

---

## Tech stack
- HTML5, CSS3 (vanilla), JavaScript (vanilla)  
- Static hosting friendly (GitHub Pages, Netlify) or any simple web server for local testing.

---

## Installation / Run locally
1. Clone the repo:
```bash
git clone https://github.com/b-satwik/uid-capstone-projtect-hack-store-.git
cd uid-capstone-projtect-hack-store-

    Serve locally:

# Python 3 simple server
python3 -m http.server 8000
# open http://localhost:8000

Login credentials (demo)

This project includes a client-side demo login system to simulate UID-based access. These credentials are for testing the UI only.

    Admin

        UID: admin-000

        Password: adminpass

        Access: admin dashboard (metadata editor / product management demo)

    Demo user

        UID: user-001

        Password: password123

        Access: product browsing, cart, gated downloads (client-side checks)

    Note: All authentication is purely client-side for the demo. Do not treat these credentials as secure. For production, implement server-side authentication, hashed passwords, and proper session management.

Cart & Coupon

The demo cart supports a simple coupon code flow.

    Coupon code: redeye

        Effect: Applies a 15% discount to the cart total (demo).

        How to use: On the cart/checkout screen enter coupon redeye and click Apply. The UI will show the discounted total.

        Limitations: Client-side only; intended for demo/portfolio use. For a real store, coupon validation must be done server-side.

How gated downloads work

    Product pages can include an unlock_code field in product metadata.

    When present, the UI will prompt the user for that code before revealing the external download link.

    Downloads are hosted on Mega.nz or Google Drive — the project only stores share links in product metadata.

    For stronger protection use signed URLs, server-side token checks, or time-limited links.

Example product metadata (products/metadata.json)

{
  "id": "tool-001",
  "title": "Example Pentest Tool",
  "description": "Demo tool for learning",
  "thumbnail": "products/tool-001.png",
  "storage": "mega",
  "download_url": "https://mega.nz/your-file-link",
  "unlock_code": "unlock-001",
  "price": 19.99
}

Security & ethics notes

    This repository is educational only — not production-ready.

    Never commit API keys, service account files, or OAuth secrets to the repository.

    Do not distribute real malware or use tools against systems you do not have explicit permission to test.

    If you make this project public, clearly label its purpose and usage restrictions.

Contributing

    Fork the repo, create a feature branch, and open a pull request with a clear description.

    Keep binary files out of source control. Use Mega/Drive share links or a release artifact strategy.

Contact

Maintainer: Bala Satwik
Project site / portfolio: echouserbalasatwik.wordpress.com
