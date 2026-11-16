# Photon

Benchmark en C para medir operaciones de CPU y velocidad de disco. Parte del ecosistema de herramientas de sistema con temática de física de partículas: **Quark**, **Neutron**, **Photon**, **Tachyon**, **Gluon**, **Electron**, **Átomo**.

## ¿Qué mide?

- **CPU:** operaciones aritméticas en bucle (usando `volatile` para evitar que el compilador las optimice).
- **Disco:** velocidad de escritura/lectura usando `fsync` para forzar la escritura física.

## 🛠️ Requisitos

- **GCC** o **Clang**
- **Linux** (usa `fsync` de POSIX)

### Instalación de dependencias

**Arch Linux / Manjaro:**
```bash
sudo pacman -S base-devel