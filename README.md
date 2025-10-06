# Cryptography

Et simpelt C-program, der kan **kryptere og dekryptere tekst** ved brug af enten **Caesar-** eller **Vigenère-metoden**.  
Programmet tager input direkte fra terminalen i formatet:


- `{mode}` = `e` eller `encrypt` for kryptering, `d` eller `decrypt` for dekryptering  
- `{cipher}` = `c`/`caeser` eller `v`/`vigenere`  
- `{text}` = Tekst bestående af store bogstaver (A-Z)  
- `{key}` = Kun nødvendig ved Vigenère-kryptering/dekryptering (kan udelades ved Caesar)

Eksempel:
e c HELLO
d v FHJLN KEY
---

## Brug
```bash
gcc Cryptography.c -o Cryptography
./Cryptography
```

Programmet vil herefter vente på brugerinput.

Hvis der ikke angives en key ved Caesar, fortsætter programmet automatisk.

Funktioner

- caeser_encrypt() – Krypterer tekst med fast shift-værdi (CEASER_SHIFT, default = 3)

- caeser_decrypt() – Dekrypterer tekst med samme shift

- vigenere_encrypt() – Krypterer tekst ud fra nøglen

- vigenere_decrypt() – Dekrypterer tekst ud fra nøglen

Automatisk håndtering af manglende key
Understøtter kun store bogstaver (A-Z)

Filer

- Cryptography.c – Programfilen med både Caesar og Vigenère-implementering
- kryptering_dekryptering.png – Diagram, der viser programmets logik
