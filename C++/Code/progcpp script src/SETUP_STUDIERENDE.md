# ProgC++ – Einrichtung der Arbeitsumgebung
## WS 2026/27

**Prof. Adrian Müller · PSM-1, CSM**

Diese Anleitung richtet die Arbeitsumgebung für Teilnehmende der Vorlesung
**ProgC++** ein. Wir gehen in **drei Stufen** vor – Sie benötigen zunächst nur
die Kommandozeilen-Werkzeuge:

| Stufe | Werkzeug | Wann? |
|-------|----------|-------|
| 1️⃣ | **g++ & make** (Compiler + Build) | **jetzt** – für alle Übungen und Beispiele |
| 2️⃣ | **VS Code** (Editor/IDE) | sobald wir vom reinen Terminal-Workflow umsteigen |
| 3️⃣ | **GitHub Copilot** (KI-Assistent) | ab Mitte des Semesters, Ankündigung in der Vorlesung |

> 📦 **Hinweis zum Kurs-ZIP:** Das Verzeichnis, in das Sie das ZIP entpacken,
> ist **beliebig**. **Alle Pfade in Skript, Makefiles und Übungen sind
> relativ** – die Beispiele funktionieren daher von jedem Ort aus
> (`D:\progc++`, `C:\Users\anna\progc++`, … alles geht).

---

## 1. Stufe 1: g++ & make (Kommandozeile)

### 1.1 Windows 11

#### MSYS2 installieren

MSYS2 ist der Paketmanager, der uns `g++` (Compiler), `make` (Build-Werkzeug)
und später `gdb` (Debugger) liefert – alles aus einer Quelle, garantiert
kompatibel miteinander.

```{warning}
Mischen Sie niemals mehrere Umgebungen (z. B. Cygwin UND MSYS2)!
Das führt zu Linker-Fehlern wie `undefined reference to __cxa_atexit`.
```

**Schritt 1:** Installer von **https://www.msys2.org** herunterladen:

```
┌─────────────────────────────────────────────────────────────┐
│  🌐 msys2.org                                               │
│                                                             │
│   ┌───────────────────────────────────────────────────┐     │
│   │   ⬇  MSYS2 Installation                          │     │
│   │      (msys2-x86_64-latest.exe)                   │     │
│   └───────────────────────────────────────────────────┘     │
└─────────────────────────────────────────────────────────────┘
```

**Schritt 2:** Installer ausführen. **Standardpfad `C:\msys64` beibehalten:**

```
┌─ MSYS2 Setup ────────────────────────────────┐
│                                              │
│  Installationsordner:                        │
│  ┌──────────────────────────────┐            │
│  │ C:\msys64                    │ ✔ BEIBEHALTEN │
│  └──────────────────────────────┘            │
│                                              │
│         [ Abbrechen ]   [ Weiter → ]         │
└──────────────────────────────────────────────┘
```

**Schritt 3:** Nach der Installation öffnet sich das **MSYS2-Terminal**
(dunkles Fenster). Dort eingeben:

```bash
pacman -Syu
```
→ Terminal schließt sich evtl. und fordert zum Neustart auf → neu öffnen,
wiederholen bis `nothing to update`.

Danach die Werkzeuge installieren (alles in einem):

```bash
pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb make
```

```
┌─ MSYS2-Terminal (MSYS) ──────────────────────────────────────┐
│ $ pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb make │
│ Pakete werden heruntergeladen …                              │
│ resolving dependencies …                                    │
│ Installieren: gcc 15.2.0, gdb 16.3, make 4.4.1 …            │
│ [Y]  ← mit Y + Enter bestätigen                             │
└─────────────────────────────────────────────────────────────┘
```

#### PATH-Einträge: Das MÜSSEN Sie manuell eintragen ⚠️

Damit Windows `g++` und `make` in **jedem** Terminal findet, tragen Sie beide
MSYS2-Ordner in die Umgebungsvariable `Path` ein. Das ist der einzige
manuelle Eingriff im System – er ist **zwingend erforderlich**:

```
┌─ Windows-Einstellungen → "Umgebungsvariablen bearbeiten" ────┐
│                                                              │
│  Benutzervariablen:                                          │
│  ┌─────────────────────────────────────────────────────┐    │
│  │  Name          │ Wert                               │    │
│  ├────────────────┼────────────────────────────────────┤    │
│  │  Path          │ [ Bearbeiten… ]                    │    │
│  └────────────────┴────────────────────────────────────┘    │
│                                                              │
│  ┌─ Path bearbeiten ────────────────────────────────┐        │
│  │                                                   │       │
│  │   ✔ C:\msys64\mingw64\bin      ← g++, gdb       │        │
│  │   ✔ C:\msys64\usr\bin          ← make          │        │
│  │                                                   │       │
│  │  ┌─────────────────────────────────────────┐    │       │
│  │  │ C:\msys64\mingw64\bin                [Neu]│    │       │
│  │  │ C:\msys64\usr\bin                        │    │       │
│  │  └─────────────────────────────────────────┘    │       │
│  │              [ OK ]  [ OK ]  [ OK ]              │       │
│  └───────────────────────────────────────────────────┘       │
└──────────────────────────────────────────────────────────────┘
```

**Beide Zeilen einzeln mit „Neu" eintragen**, Reihenfolge:
1. `C:\msys64\mingw64\bin` ← hier liegen `g++.exe`, `gdb.exe`
2. `C:\msys64\usr\bin` ← hier liegt `make.exe`

Dann **alle Dialoge mit OK schließen** und ein **neues** Terminal öffnen.

#### Installation verifizieren

Neues PowerShell- oder cmd-Fenster:

```powershell
g++ --version
gdb --version
make --version
where.exe g++
where.exe make
```

```
┌─ PowerShell (NEU geöffnet!) ────────────────────────────────┐
│ PS D:\> g++ --version                                       │
│ g++.exe (Rev8, Built by MSYS2 project) 15.2.0               │
│                                                             │
│ PS D:\> make --version                                      │
│ GNU Make 4.4.1                                               │
│ Built for x86_64-pc-msys          ← genau so muss das stehen!│
│                                                             │
│ PS D:\> where.exe make                                      │
│ C:\msys64\usr\bin\make.exe      ← muss ERSTE Zeile sein     │
│ (falls hier C:\cygwin64\... steht → PATH-Reihenfolge prüfen)│
└─────────────────────────────────────────────────────────────┘
```

### 1.2 macOS (Apple Silicon & Intel)

#### Homebrew installieren

Terminal öffnen („Andere" → „Terminal"), Installationskommando von
**https://brew.sh** kopieren und ausführen:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Am Ende zeigt Homebrew zwei Zeilen „Next steps" (echo + eval …) – **beide
ausführen**, damit `brew` im PATH liegt. Das ist unter macOS der einzige
manuelle PATH-Eingriff.

#### Werkzeuge installieren

```bash
brew install gcc make
```

Verifikation:

```bash
g++-13 --version     # g++-13 (Homebrew GCC 13.x)
gmake --version      # GNU Make 4.4 (heißt hier gmake)
```

> 💡 macOS bringt bereits Apple-clang mit. Für die Vorlesung nutzen wir
> Homebrews GNU-g++ (`g++-13`), weil unsere Makefiles GNU-spezifische
> Warn-Flags verwenden. Die Kurs-Makefiles rufen es automatisch auf –
> Sie müssen nichts weiter tun.

---

## 2. Arbeiten mit den Kurs-Materialien (Stufe 1 reicht!)

Das Kurs-ZIP entpacken Sie an einen **beliebigen** Ort. Alle Beispiele
arbeiten mit **relativen Pfaden** – kein Konfigurationsschritt nötig:

```
progc++/                       ← beliebig entpackt
├── SETUP_STUDIERENDE.md       ← diese Anleitung
├── script/                    ← Vorlesungsskript (HTML)
└── src/                       ← alle Beispielprogramme
    ├── Makefile               ← Haupt-Makefile
    ├── Makefile.include       ← globale Build-Regeln (PLATTFORM-ERKENNUNG)
    ├── lib/                   ← gemeinsame Bibliotheken (SIMPLETEST …)
    ├── ppc00/                 ← LE 00: Einführung
    ├── ppc01/                 ← LE 01 …
    ├── ppc04/                 ← Klassen …
    ├── ppc50/                 ← C++20 Concepts …
    └── …
```

### Build-Workflow im Terminal

```powershell
cd <beliebig>\progc++\src\ppc00     # in ein Kapitel wechseln
make                                 # alle Programme des Kapitels bauen
./ppc00a0.exe                        # ausführen (macOS: ./ppc00a0)
make clean                           # Build-Dateien entfernen
```

**Kontrolle:** `./ppc00a0.exe` muss ausgeben:

```
Compiler-Version:	202002
```
(202002 = C++20 – damit kompiliert die gesamte Vorlesung.)

### Was Sie über die Makefiles wissen müssen

Die Kurs-Makefiles **erkennen Ihre Plattform automatisch** (Windows / Linux /
macOS) und stellen die richtigen Compiler- und Standard-Einstellungen bereit:

| Plattform | Compiler | C++-Standard | Hinweis |
|---|---|---|---|
| Windows (MSYS2) | g++ 15.x | C++20 | `make` aus `usr\bin` |
| macOS (Homebrew) | g++-13 | C++20 | `gmake` bzw. `make` |
| Linux | g++ | C++20 | (Labor-Umgebung) |

```
┌─ Was passiert bei "make"? ─────────────────────────────────┐
│                                                             │
│  make liest Makefile des Kapitels                            │
│        │                                                    │
│        ├──▶ g++ -std=c++20 -Wall -Wextra -g  (compilieren)  │
│        │                                                    │
│        ├──▶ g++ *.o -lm -o programm          (linken)       │
│        │                                                    │
│        └──▶ Programme + Tests laufen                        │
│                                                             │
│  Doku-Ziele (.html/.extract/AVR) werden ohne                │
│  Dozenten-Werkzeuge automatisch übersprungen ✔              │
└─────────────────────────────────────────────────────────────┘
```

> ⚠️ **Nur EINE Umgebung:** Wenn `make`-Läufe mysteriös scheitern
> (`/cygdrive/...`-Pfade, `__cxa_atexit`), haben Sie vermutlich Cygwin
> installiert. Prüfen Sie mit `where.exe make`, dass **MSYS2** zuerst
> im PATH steht.

### Häufige Fehler (Stufe 1)

| Symptom | Lösung |
|---|---|
| `'make' is not recognized` | PATH-Eintrag `C:\msys64\usr\bin` fehlt, oder Terminal nicht neu geöffnet |
| `g++ ... /cygdrive/d/... No such file` | Sie nutzen Cygwin-make → PATH-Reihenfolge prüfen (`where.exe make`) |
| `make: Clock skew detected` | Harmlose MSYS2-Zeitstempel-Warnung → einfach nochmal `make` |
| `AVR-Ziele werden übersprungen` | **Erwartet** – AVR (LE 50–55) braucht die Labor-Toolchain |
| `make ppc00b1` → Compilerfehler | **Beabsichtigt** – didaktisches Beispiel „Doppelte Definition" |

---

## 3. Stufe 2: VS Code

Sobald wir in der Vorlesung vom Terminal- zum Editor-Workflow wechseln:

### 3.1 Installation

1. **https://code.visualstudio.com** → Download → Standardinstallation
2. VS Code starten → `Ctrl+Shift+X` (Windows) / `Cmd+Shift+X` (macOS) →
   nach **„C/C++"** suchen → Extension **„C/C++" von Microsoft** installieren:

```
┌─ VS Code → Extensions ───────────────────────────────────────┐
│  🔍 Suche: C/C++                                            │
│                                                              │
│  ┌────────────────────────────────────────────────────┐     │
│  │ C C/C++  Microsoft  ★ 4.9  ↓ 40M                  │     │
│  │ C/C++ IntelliSense, debugging…                     │     │
│  │                                        [ Install ] │     │
│  └────────────────────────────────────────────────────┘     │
└──────────────────────────────────────────────────────────────┘
```

### 3.2 Projekt öffnen (Pfade bleiben relativ!)

```
┌─ VS Code ────────────────────────────────────────────────────┐
│  File → Open Folder…  →  <beliebig>\progc++\src             │
│                                                              │
│  📁 EXPLORER  src                                            │
│  ├── 📁 .vscode          ← FERTIG konfiguriert!             │
│  │     launch.json       ← Debug (F5)                       │
│  │     tasks.json        ← Build-Task                       │
│  │     c_cpp_properties.json ← IntelliSense                  │
│  ├── 📁 ppc00/          ← z.B. ppc00a0.cc öffnen            │
│  └── …                                                      │
└──────────────────────────────────────────────────────────────┘
```

Die Konfiguration in `src/.vscode/` ist **mitgeliefert und für Windows und
macOS/Linux vorbereitet** (der Build-Task und die Debug-Konfiguration wählen
die richtige Variante automatisch anhand Ihres Betriebssystems):
- **Windows:** `g++` → `.exe`, Debugging mit **GDB**
- **macOS/Linux:** `g++-13` bzw. `g++`, Debugging mit **LLDB**

In der Regel müssen Sie nichts anpassen. Nur falls VS Code beim ersten Start
 IntelliSense-Wellenlinien zeigt: `Ctrl/Cmd+Shift+P` → **„C/C++: Select a
 Configuration"** → **Win32** (Windows) bzw. **macOS** auswählen.

### 3.3 Debuggen mit F5

1. Eine `.cc`-Datei öffnen (z. B. `ppc04/ppc0401.cc`)
2. **F5** → Konfiguration wählen:
   - Windows: „C/C++: g++ Debug (Windows, aktive Datei)"
   - macOS: „C++ Debug (macOS/Linux, aktive Datei)"
3. VS Code kompiliert mit `-Wall -Wextra -std=c++20 -g` und hält an der
   **ersten Zeile in `main()`** an:

```
┌─ DEBUG KONSOLE ─────────────────────────────────────────────┐
│                                                              │
│  int main() {                                          ◀ STOP│
│ ▶    Point p1(1.0, 2.0);      ← Breakpoint (roter Punkt)   │
│      Point p2 = p1;                                          │
│                                                              │
│  F10 = Einzelschritt   F11 = Hineinspringen                 │
│  Shift+F11 = Herausspringen   F5 = Weiter   Shift+F5 = Stop │
└──────────────────────────────────────────────────────────────┘
```

---

## 4. Stufen-Übersicht

```
┌─────────────────────────────────────────────────────────────┐
│                                                             │
│   STUFE 1 (JETZT)      STUFE 2              STUFE 3          │
│   ┌──────────┐         ┌──────────┐         ┌──────────┐     │
│   │ g++/make │   ──▶   │ VS Code │   ──▶   │ Copilot  │     │
│   │ Terminal │         │ Editor  │         │ KI-Assist.│    │
│   └──────────┘         └──────────┘         └──────────┘     │
│                                                             │
│   Übungen,              Komfort:             Ab Mitte        │
│   Beispiele,            IntelliSense,        des Semesters   │
│   Makefiles             Debugging (F5)       (Ankündigung    │
│                                             in der VL)      │
└─────────────────────────────────────────────────────────────┘
```

**GitHub Copilot (Stufe 3, Vorschau):** Kostenfrei über GitHub Education
(https://education.github.com) mit Immatrikulationsbescheinigung. Details
zum Workflow folgen in der Vorlesung – Copilot-Vorschläge müssen Sie immer
verstehen und erklären können.

---

## 5. Checkliste

- [ ] MSYS2 installiert (`C:\msys64`, Standardpfad)
- [ ] `pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb make`
- [ ] **PATH: `C:\msys64\mingw64\bin` UND `C:\msys64\usr\bin` eingetragen**
- [ ] Neues Terminal: `g++ --version` → 15.x, `make --version` → 4.4
- [ ] Kurs-ZIP an beliebigem Ort entpackt
- [ ] `make` in `src/ppc00` → `./ppc00a0.exe` → `Compiler-Version: 202002`
- [ ] (macOS: `brew install gcc make`, „Next steps" ausgeführt)
- [ ] (später) VS Code + Extension „C/C++" von Microsoft
- [ ] (später) GitHub Education / Copilot

**Bei Problemen:** Sprechstunde Mi., 13:00–14:00 Uhr, Raum H234 ·
OpenOLAT: https://olat.vcrp.de/url/RepositoryEntry/5311660275

---

*ProgC++ · Prof. Adrian Müller · CSM · WS 2026/27*