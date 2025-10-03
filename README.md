# Hack Store — UID Capstone Project

**Repository:** `uid-capstone-projtect-hack-store-`
**Author / Maintainer:** Bala Satwik
**License:** Apache-2.0.

> ⚠️ **Ethical Use Only.** This project is intended for education, defensive research, and portfolio purposes. Do **not** use the materials for illegal activity. Always obtain explicit permission before testing any systems you do not own.

---

## Project Summary

**Hack Store** is a frontend e-commerce demonstration built as a capstone/UID project. It showcases a proof-of-concept for gated distribution of pentesting tools and learning resources. The UI demonstrates **UID-based access control**, gated downloads (via an unlock code or authenticated session), and the use of external cloud drives (Mega / Google Drive) for hosting large assets.

---

## Key Features

* **Clean Frontend:** Uses HTML, vanilla CSS, and JavaScript for product listing and product detail pages.
* **Gated Access:** Implements a UID-driven login/session model (demo using `localStorage`/cookie) to restrict download visibility.
* **Conditional Downloads:** Product pages reveal external download links only after successful UID/authentication or unlock code verification.
* **External Integration:** References external storage like Mega.nz and Google Drive share links for binaries (assets are stored off-repository).
* **Architecture Documentation:** Includes wiring/architecture notes to clearly show how pages and access control interact.

---

## Tech Stack

* **Frontend:** HTML5, CSS3 (vanilla), JavaScript (vanilla)
* **Hosting (Optional):** Simple static hosting (e.g., GitHub Pages, Netlify) or any lightweight web server for local testing.
* **External Storage:** Mega.nz, Google Drive (used for share links only — binaries are stored off-repo).

---

## Repository Structure (Recommended)

This structure provides a clean separation for the core web files, data, and documentation.

 main.html
    │
    └──► login.html   (user enters UID / unlock code)
             │
             └──► index.html   (product list)
                     │
                     └──► product.html?id=<UID>
                               │
                               └──► Download (Mega / Google Drive link)
---

## Install / Run Locally

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/b-satwik/uid-capstone-projtect-hack-store-.git](https://github.com/b-satwik/uid-capstone-projtect-hack-store-.git)
    cd uid-capstone-projtect-hack-store-
    ```

2.  **Serve locally** using any lightweight web server (you must serve it to handle page-to-page navigation):

    ```bash
    # Python 3 simple server
    python3 -m http.server 8000
    # or use 'serve' from npm
    npx serve .
    ```

3.  Open your browser and navigate to **`http://localhost:8000/main.html`** to test the UI.

---

## Wiring / Architecture (Page Direction)

The application follows a linear access flow, gated by the **UID verification** at the beginning of the user journey.

The primary navigation flow is as follows:

1.  **`main.html`** (Landing Page)
    $\downarrow$
2.  **`login.html`** (Gating Page)
    * The user is directed here from the landing page.
    * The user must enter their **UID** or an unlock code to establish a session.
    $\downarrow$
3.  **`index.html`** (Product List)
    * Visible only after successful verification on `login.html`.
    * Displays a list of available products.
    $\downarrow$
4.  **`product.html?id=<PRODUCT_ID>`** (Product Detail)
    * The page checks for a valid UID session (`localStorage` or cookie).
    * If valid, the user may be asked for a secondary **unlock code**.
    $\downarrow$
5.  **Download Link** (Mega / Google Drive)
    * The external link is revealed only after all authentication/verification steps are complete.

---

## Security & Ethics Notes

* This repository demonstrates **client-side concepts only** and **does not** represent a secure production access control system.
* **DO NOT** commit API keys, service account files, or direct OAuth credentials to the repository.
* For stronger access control in a production environment, you should implement server-side signed URLs or time-limited access tokens.
* Always label tools clearly and only use pentest tools in authorized, non-production environments with explicit permission.

---

## Contributing

1.  Fork the repo.
2.  Create a feature branch (`git checkout -b feature/my-new-feature`).
3.  Open a Pull Request (PR) with a clear description of your changes.

**Note:** Please keep binaries out of version control and continue to prefer external hosting for all downloadable assets.
