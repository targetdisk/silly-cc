# Silly CC

<p align="center">
  <a href="./LICENSE">
    <img alt="License: AGPLv3+TRANS RIGHTS" src="./img/license-badge.svg">
  </a>
</p>

`silly-cc` is a build system-agnostic wrapper around Clang that automagically
produces pieces needed to build a JSON compilation database.  It is a drop-in
replacement for `clang` in any build system where you can override the `cc`
command some sort of `CC` variable.

There is also a script included in here that can `merge` all the JSON data into
a single `compile_commands.json` file (used by `clangd` and friends to fuel your
LSP-aware text editors' tab completion).
