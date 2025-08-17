# 🏆 ICPC Team Repository

Este repositorio documenta **nuestra preparación y participación** en competencias (ICPC/CF/Gym). Reúne material básico, práctica por áreas, y soluciones de concursos, con foco en velocidad, claridad y trazabilidad.

---

## 🎯 Objetivos

* Centralizar **apuntes** (C++ básico, plantillas, cheatsheets).
* Organizar **práctica por especialidad** (Matemática, DP, Grafos).
* Versionar **soluciones de competencia** con entradas/salidas y post-mortems.
* Mantener **estándares de código y flujo de trabajo**.

---

## 📁 Estructura del directorio

```
.
├── 00-Basico/                          # Fundamentos de C++ y recursos comunes
│   ├── cheat-sheets/                   # PDFs/MD con resúmenes (C++, STL, Git)
│   ├── templates/                      # Templates (main.cpp, IO, debug)
│   ├── ejemplos/                       # Programas simples de referencia
│   └── README.md                       # Guía de uso de esta carpeta
│
├── 01-Practica/                        # Práctica por área (progresiva y etiquetada)
│   ├── Grafos-EstructuraDeDatos/                       # Alejo
│   │   ├── temas/                      # (BFS/DFS, shortest paths, flow, LCA, etc.)
│   │   ├── problemas/                  # ejercicios con I/O y notas
│   │   └── README.md
│   ├── Matematica-TeoriaDeNumeros/                     # Augusto
│   │   ├── temas/                      # (criba, CRT, combinatoria, geometría, etc.)
│   │   ├── problemas/                  # ejercicios con I/O y notas
│   │   └── README.md
│   ├── ProgramacionDinamica-Strings/                   # Lucas
│   │   ├── temas/                      # (knapsack, bitmask, optimizaciones, etc.)
│   │   ├── problemas/                  # ejercicios con I/O y notas
│   │   └── README.md
│   └── README.md                       # Guía de organización de 01-Practica
│
├── 02-Competencia/                     # Enunciados y soluciones de concursos
│   ├── YYYY-MM-DD_ContestName/         # 1 carpeta por concurso
│   │   ├── soluciones/                 # soluciones
│   │   ├── editorial.md                # ideas clave + errores + mejoras
│   │   └── scoreboard.md               # progreso y tiempos
│   └── README.md
│
└── README.md                           # Este archivo
```

---

## 👥 Roles del equipo

* **Matemáticas y Teoría De Números — Augusto**

  * Teoría de números, combinatoria, geometría, álgebra modular.
  * Mantiene plantillas y cheats de combinatoria/CRT/geometry.
* **Programación Dinamica y Strings — Lucas**

  * DP clásica, bitmask, optimizaciones (divide & conquer, CHT), strings DP.
  * Mantiene plantillas de DP y guías de optimización.
* **Grafos y Estructura De Datos — Alejo**

  * Shortest paths (Dijkstra, SPFA), flows (Dinic), matching (HK/Hungarian), árboles (LCA, DSU on tree).
  * Mantiene plantillas de grafos/estructura de datos (DSU, Segment Tree si aplica).

> Nota: todos revisan PRs fuera de su área al menos a *alto nivel* para conocimiento cruzado.

---

## 🔧 Estándares de código

* **C++17/20** (según judge). Usar `#include <bits/stdc++.h>` y `ios::sync_with_stdio(false); cin.tie(nullptr);`.
* Archivos: una solución por archivo `X.cpp` con `solve()` y `main()` minimal.
* **Nombres**: `snake_case` para variables, `CamelCase` para structs/clases, `UPPER_SNAKE` para constantes.
* **Límites** comentados al inicio del archivo (N, M, valores, complejidad objetivo).
* **Asserts** y `debug(...)` detrás de `#ifdef LOCAL`.

---

## 🧪 I/O de pruebas

* Cada problema puede tener `in/` y `out/` con casos **mínimos**, **random pequeños** y **corner cases**.
* Script opcional para test local (por ejemplo `run_test.sh`).

---

## 🗺️ Convenciones por práctica

* `01-Practica/<Area>/temas/<tema>/README.md` con descripción corta + enlaces.
* `01-Practica/<Area>/problemas/<id>/` con:

  * `README.md` (enunciado resumido + idea + complejidad + trampas).
  * `<slug>.cpp`, `in/`, `out/`.

---

## 📦 Plantillas recomendadas

* `00-Basico/templates/main.cpp` — base con IO rápido y `solve()`.
* `00-Basico/templates/debug.hpp` — macros `dbg(...)` bajo `#ifdef LOCAL`.

---

## 🧭 Roadmap sugerido

* **Semanal**: 1 contest + 2 sesiones por área (Mate/DP/Grafos).
* **Post-mortem**: actualizar `editorial.md` con errores y mejoras.
* **Rotación**: cada mes intercambiar 1 problema fuera de tu área para versatilidad.

---

## 📄 Licencia


---

## 🙌 Créditos

* Equipo: **Augusto (Matemáticas)**, **Lucas (DP)**, **Alejo (Grafos)**.
* Mentores, editoriales y recursos consultados se listarán en cada carpeta.
