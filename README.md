# Wordlists hashes

This repository contains the hashes of popular wordlists. 

The wordlists are put into CSV files with the following format:

- `String` - The word in the wordlist
- `SHA256` - The SHA256 hash of the word
- `MD5` - The MD5 hash of the word

The CSV files are generated using the `src/hash.c` program which can generate these files in a few seconds (Unless your hashing RockYou).

> **Warning** 
>
> Only use for educational purposes. Do not use this against any system without permission. I am not responsible for any actions you do with the wordlists.

Thanks to [kkrypt0nn/wordlists](https://github.com/kkrypt0nn/wordlists) for the wordlists.

## Wordlists

There are currently `5` wordlists in this repository:

- [Big](wordlists/big.txt) - 20,468 words
- [CIRT default usernames](wordlists/cirt-default-usernames.txt) - 827 words
- [English](wordlists/english.txt) - 352,297 words
- [Nmap](wordlists/nmap.lst) - 4,999 words
- [Names](wordlists/names.txt) - 10,177 words