Hack Store — UID Capstone Project

Repository: uid-capstone-projtect-hack-store-
Author / Maintainer: Bala Satwik

⚠️ Ethical use only. This project is for education, defensive research, and portfolio purposes. Do not use the materials for illegal activity. Always obtain explicit permission before testing any systems you do not own.

Project summary

Hack Store is a frontend e-commerce demo built as a UID capstone project to showcase gated distribution of pentesting tools and learning resources. The UI demonstrates a UID-based client-side login flow, gated product downloads (unlock code or authenticated session), and the use of external cloud drives (Mega / Google Drive) for hosting large assets. Binaries are stored off-repo and referenced by share links.

Key features

Simple frontend (HTML / CSS / JavaScript) product catalog and product detail pages.

UID-driven login/session model (localStorage demo) to gate downloads.

Product pages reveal external download links only after UID / unlock code verification.

Cart support with a demo coupon code for discounts.

External storage integration: Mega.nz / Google Drive links for large files (do not commit binaries).

Wiring flow: main.html → login.html → index.html → product.html → download.

Tech stack

HTML5, CSS3 (vanilla), JavaScript (vanilla)

Static hosting friendly (GitHub Pages, Netlify) or any simple web server for local testing.

Installation / Run locally

Clone the repo:
