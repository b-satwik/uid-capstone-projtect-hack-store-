# Hack Store — UID Capstone Project

**Repository:** `uid-capstone-projtect-hack-store-`  
**Author / Maintainer:** Bala Satwik  
**License:** Apache-2.0. :contentReference[oaicite:1]{index=1}

> ⚠️ **Ethical use only.** This project is for education, defensive research, and portfolio purposes. Do **not** use the materials for illegal activity. Always obtain explicit permission before testing any systems you do not own.

---

## Project summary

Hack Store is a frontend e-commerce demo built as a capstone/UID project to showcase gated distribution of pentesting tools and learning resources. The UI demonstrates UID-based access control, gated downloads (unlock code or authenticated session), and the use of external cloud drives (Mega / Google Drive) for hosting large assets.

---

## Key features

- Clean frontend (HTML / CSS / JavaScript) for product listing and product detail pages.  
- UID-driven login/session model (localStorage/cookie demo) to gate downloads.  
- Product pages that reveal external download links only after UID/auth or unlock code verification.  
- External storage integration by referencing Mega.nz and Google Drive share links (binaries are stored off-repo).  
- Wiring / architecture notes included in `docs/` to show how pages interact.

---

## Tech stack

- HTML5, CSS3 (vanilla), JavaScript (vanilla)  
- Optional: simple static hosting (GitHub Pages, Netlify) or any lightweight web server for local testing.  
- External storage for binaries: Mega.nz, Google Drive (share links only — do not store secrets in repo).

---

## Repo structure (recommended)

hack-store/
├─ index.html # landing / products list
├─ product.html # product detail / gated download
├─ login.html # UID/login interface
├─ dashboard.html # admin / metadata editor (optional)
├─ styles/
│ └─ main.css
├─ scripts/
│ └─ app.js
├─ products/ # product metadata (JSON) + thumbnails
├─ assets/ # logos, icons
├─ docs/ # wiring.md, diagrams
└─ LICENSE # Apache-2.0


---

## Install / run locally

1. Clone the repo:
   ```bash
   git clone https://github.com/b-satwik/uid-capstone-projtect-hack-store-.git
   cd uid-capstone-projtect-hack-store-

    Serve locally (examples):

    # Python 3 simple server
    python3 -m http.server 8000
    # or use 'serve' from npm
    npx serve .

    Open http://localhost:8000 and test the UI.

How to add a product

    Add metadata to products/metadata.json (or via admin UI); example:

    {
      "id": "uid001",
      "title": "Example Pentest Tool",
      "description": "Short description",
      "thumbnail": "products/example.png",
      "storage": "mega",
      "download_url": "https://mega.nz/your-file-link",
      "unlock_code": "optional-code"
    }

    Upload the binary/zip to Mega or Google Drive; paste the share link in download_url.

    If using an unlock_code, the frontend will require it before revealing download_url.

Wiring / architecture (brief)

    index.html lists products and links to product.html?id=<id>.

    product.html checks for a valid UID session (localStorage or cookie); if missing, prompts to login or input UID.

    After UID verification (client demo), user is asked for unlock code (if present) and then given the external link.

    Admin dashboard edits product metadata (JSON) — for production use a real backend and signed/time-limited links.

Include a wiring diagram in docs/wiring.md or docs/wiring.png for visual clarity.
Security & ethics notes

    This repo demonstrates concepts only — not secure production access control.

    Do not commit API keys, service account files, or direct OAuth credentials.

    Consider server-side signed URLs or time-limited tokens if stronger access control is required.

    Label tools clearly and only use pentest tools in authorized environments.

Contributing

    Fork the repo

    Create a branch (feature/my-feature)

    Open a PR with a clear description

Please keep binaries out of version control and prefer external hosting.
Contact

Maintainer: Bala Satwik
Project site / portfolio: echouserbalasatwik.wordpress.com
