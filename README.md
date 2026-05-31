# Labecoin Game AI

![C++](https://img.shields.io/badge/C++-Inteligencia%20Artificial-00599c?style=for-the-badge&logo=cplusplus)&nbsp;![IA](https://img.shields.io/badge/Algoritmos-B%C3%BAsqueda%20Local-orange?style=for-the-badge)&nbsp;![Eclipse](https://img.shields.io/badge/IDE-Eclipse%20CDT-2C2255?style=for-the-badge&logo=eclipseide)&nbsp;![Mapas](https://img.shields.io/badge/Mapas-10%20Niveles-green?style=for-the-badge)&nbsp;![POO](https://img.shields.io/badge/Programaci%C3%B3n-Orientada%20a%20Objetos-blueviolet?style=for-the-badge)

> **Labecoin Game AI** es un juego de laberinto en C++ donde un agente inteligente recorre un tablero recogiendo monedas usando algoritmos de **búsqueda local**: Escalada Simple, Máxima Pendiente y Escalada Estocástica. Desarrollado como proyecto final de la asignatura IASI.

---

## 📋 Descripción del Proyecto

**Labecoin** es un juego de tablero donde un agente automático debe recorrer un laberinto y recoger el máximo número de monedas posible.  
El proyecto implementa y compara tres **algoritmos de búsqueda local** clásicos de Inteligencia Artificial, cada uno con una estrategia distinta para explorar el espacio de soluciones:

| Algoritmo | Estrategia | Descripción |
|---|---|---|
| **Escalada Simple** | `EscaladaSimple` | Elige el primer vecino que mejore la solución actual |
| **Máxima Pendiente** | `MaximaPendiente` | Evalúa todos los vecinos y elige el mejor de ellos |
| **Escalada Estocástica** | `ESEstocastico` | Selecciona aleatoriamente entre los vecinos mejores |

Las funciones de evaluación usadas son:
- **`FuncionDistancia`** — minimiza la distancia recorrida.
- **`FuncionRentabilidad`** — maximiza la relación monedas recogidas / distancia recorrida.

---

## 🏗️ Estructura del Proyecto

```txt
Labecoin-Game-AI/
├── src/                           # Código fuente principal
│   ├── IASI.cpp                   # Punto de entrada del programa
│   ├── Tablero.cpp / .h           # Lógica del tablero y laberinto
│   ├── Coordenada.cpp / .h        # Representación de posiciones en el mapa
│   ├── Moneda.cpp / .h            # Clase de monedas del tablero
│   ├── vectorMonedas.cpp / .h     # Contenedor de monedas
│   ├── Fichero.cpp / .h           # Lectura de mapas desde ficheros .txt
│   ├── EscaladaSimple.cpp / .h    # Algoritmo de Escalada Simple
│   ├── MaximaPendiente.cpp / .h   # Algoritmo de Máxima Pendiente
│   ├── ESEstocastico.cpp / .h     # Algoritmo de Escalada Estocástica
│   ├── FuncionDistancia.cpp / .h  # Función heurística de distancia
│   └── FuncionRentabilidad.cpp / .h # Función heurística de rentabilidad
├── Debug/                         # Binarios compilados (Eclipse CDT)
├── LABECOIN1.txt                  # Mapa nivel 1
├── LABECOIN2.txt                  # Mapa nivel 2
├── ...                            # (hasta LABECOIN10.txt)
├── Documentacion.pdf              # Documentación técnica del proyecto
├── EnunciadoProyecto_IASI2223.pdf # Enunciado oficial del proyecto
└── README.md                      # Documentación del proyecto
```

---

## ⚙️ Requisitos y Compilación

### Windows (MinGW + Eclipse CDT)

```bash
# Requisitos:
# - Compilador MinGW (paquete básico + toolchain)
# - PATH de MinGW configurado en variables de entorno
# - Eclipse CDT con build y run config en modo MinGW
```

1. Abrir el proyecto en **Eclipse CDT**.
2. Configurar el **Run Configuration** seleccionando el `.exe` en `/Debug`.
3. Compilar con `Build Project` y ejecutar.

### Linux / GNU (g++)

```bash
git clone https://github.com/sorgazb/Labecoin-Game-AI.git
cd Labecoin-Game-AI/src
g++ -o labecoin *.cpp
./labecoin
```

> Los ficheros de mapa `LABECOIN1.txt` – `LABECOIN10.txt` deben estar en el mismo directorio que el ejecutable.

---

## 🗺️ Formato de los Mapas

Cada nivel se define en un fichero `.txt` con la siguiente codificación de celdas:

| Símbolo | Significado |
|---|---|
| `P` | Posición inicial del agente |
| `M` | Moneda recogible |
| `X` | Pared (celda bloqueada) |
| `.` | Celda libre |

---

## 🖥️ Ejemplos de Ejecución

<p align="center">
  <img src="https://github.com/vvaldesc/Labecoin-Game-AI/assets/124901115/2e95911a-be96-4466-9de5-17e3f8b552d2" alt="Ejemplo 1" width="600"/>
</p>

<p align="center">
  <img src="https://github.com/vvaldesc/Labecoin-Game-AI/assets/124901115/b0626153-1fa3-43d8-bb7b-0f26a5a7e331" alt="Ejemplo 2" width="600"/>
</p>

<p align="center">
  <img src="https://github.com/vvaldesc/Labecoin-Game-AI/assets/124901115/71ab8e04-5159-4724-a0dd-35ced8fc6ffb" alt="Ejemplo 3" width="600"/>
</p>

<p align="center">
  <img src="https://github.com/vvaldesc/Labecoin-Game-AI/assets/124901115/5d9b2df1-d022-433f-bd10-da39b20dc101" alt="Ejemplo 4" width="600"/>
</p>

<p align="center">
  <img src="https://github.com/vvaldesc/Labecoin-Game-AI/assets/124901115/dffddae3-c491-41ac-bbc2-8fae5e7aab9f" alt="Ejemplo 5" width="600"/>
</p>

---

## 📚 Documentación

- 📄 [Enunciado oficial del proyecto](./EnunciadoProyecto_IASI2223.pdf)
- 📄 [Documentación técnica](./Documentacion.pdf)

---

## 🤝 Contribución

Haz fork del repositorio.

Crea una rama de trabajo:

```bash
git checkout -b feature/mi-nueva-funcionalidad
```

Realiza tus cambios y haz commit.

Abre un Pull Request describiendo tus mejoras.

---

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/c/cc/UNEX.png" alt="Universidad de Extremadura" height="80"/>
  <br/><br/>
  <strong>Inteligencia Artificial y Sistemas Inteligentes (IASI)</strong> &nbsp;&middot;&nbsp; Grado en Ingeniería Informática en Computadores &nbsp;&middot;&nbsp; Universidad de Extremadura
  <br/>
  Sergio Orgaz Bravo
</p>
