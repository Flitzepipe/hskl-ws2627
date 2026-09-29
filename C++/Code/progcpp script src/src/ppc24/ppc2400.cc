// Gegenüberstellung Komposition <-> Vererbung am Beispiel Kreis-Ellipse-Problem
// <> Dieses Werk ist lizenziert unter einer http://creativecommons.org/licenses/by-nc-nd/4.0[Creative Commons Namensnennung - Nicht kommerziell - Keine Bearbeitungen 4.0 International Lizenz]

#include <cstdlib>
#include <string>
#include <numbers>
#include <cassert>
#include <vector>
#include <memory>

struct PixelBuffer {};
struct Canvas {
private:
    std::string mName; // <> Komposition
    PixelBuffer mPixelBuffer; // <> Komposition   
};

struct Shape { // <> Schnittstelle
    virtual void draw(Canvas&) const = 0;
    virtual ~Shape() = default;
};

// Diese Klasse ist zur Ableitung vorgesehen.
struct Ellipse_1 : public Shape { // Sub-Typing: Schnittstellenvererbung
    Ellipse_1(const double r1, const double r2) : mR1{r1}, mR2{r2} {}
    virtual void draw(Canvas&) const override {printf("draw E1(%g,%g)\n", mR1, mR2);}
    virtual Ellipse_1& r1(const double r) {mR1 = r; return *this;}
    virtual Ellipse_1& r2(const double r) {mR2 = r; return *this;}
    double area() const {return mR1 * mR2 * std::numbers::pi_v<double>;}
protected:
    double mR1{0};
    double mR2{0};
};

// Ansatz 1:
// Idee: Wiederverwendung des Codes aus Ellipse_1
// Mathematisch: ein Kreis "ist-eine" Ellipse mit der Invariante: mR1 == mR2
// Problem: allerdings kann über die ererbten Funktion die Invariante verletzt werden
// Dies bedeutet auch: ein Kreis "verhält-sich" wie eine Ellipse ist NICHT erfüllt
struct Circle_1 : public Ellipse_1 { // Sub-Classing: Schnittstellenvererbung
    Circle_1(const double r) : Ellipse_1{r, r} {}
    virtual void draw(Canvas&) const {printf("draw C1(%g)\n", mR1);} // <> nur zu Demo-Zecken überschrieben
};

void test1() {
    Circle_1  c1{10};    
    c1.r1(20.0); // <> Ups: verletzt Invariante Kreis: mR1 == mR2
    printf("test1: %g : %g\n", c1.area(), 20.0 * 20.0 * std::numbers::pi_v<double>);
}

// Ansatz 2:
// Idee: Wiederverwendung des Codes aus Ellipse_1
// Mathematisch: ein Kreis "ist-eine" Ellipse mit der Invariante: mR1 == mR2
// Die Invariante des Kreises wird erzwungen.
// Problem: jedoch verletzt man damit die Konformanz: ein Circle_2 verhält sich nicht wie eine Ellipse_1
// Dies wird auch dadurch deutlich, dass die beiden Mutatoren r1() und r2() für einen Kreis keine sinnvolle Bedeutung haben
struct Circle_2 : public Ellipse_1 { // Sub-Classing: Schnittstellenvererbung
    Circle_2(const double r) : Ellipse_1{r, r} {}
    virtual void draw(Canvas&) const {printf("draw C2(%g)\n", mR1);} // <> Nur zu Demo-Zwecken überschrieben
    virtual Circle_2& r1(const double r) override {mR1 = mR2 = r; return *this;} // <> Kovarianter Typ
    virtual Circle_2& r2(const double r) override {mR1 = mR2 = r; return *this;}
};

void test2(Ellipse_1& e) { // <> Aufrufer kann hier auch ein Circle_2 übergeben
    e.r1(10.0);
    e.r2(20.0); // <> Ups: e (Circle_2) ist keine Ellipse mehr: keine Konformanz zwischen Kreis und Ellipse
    
    printf("test2: %g, %g\n", e.area(), 10.0 * 20.0 * std::numbers::pi_v<double>);    
}

// Ansatz 3:
// Statt Vererbung (Sub-Classing) wird Komposition eingesetzt.
// Circle_3 erbt damit nicht mehr die komplette öffentliche Schnittstelle von Ellipse_1
// und kann damit die Invariante mR1 == mR2 sicherstellen.
// Alle Nachteile der Vererbungsvarianten (1, 2, 4, 5, 6) können damit vermieden werden.

// Diese Klasse ist NICHT zur Ableitung vorgesehen.
struct Ellipse_2 final : public Shape { // Sub-Typing 
    Ellipse_2(const double r1, const double r2) : mR1{r1}, mR2{r2} {}
    virtual void draw(Canvas&) const override {printf("draw E1(%g,%g)\n", mR1, mR2);}
    Ellipse_2& r1(const double r) {mR1 = r; return *this;}
    Ellipse_2& r2(const double r) {mR2 = r; return *this;}
    double area() const {return mR1 * mR2 * std::numbers::pi_v<double>;}
protected:
    double mR1{0};
    double mR2{0};
};
struct Circle_3 final : public Shape { // <> Sub-Typing
    Circle_3(double r) : mEllipse{r, r} {}
    virtual void draw(Canvas& c) const override {
        mEllipse.draw(c); // <> Delegation an Ellipse, weitere Funktionen müssen ebenfalls delegiert werden
    }
    Circle_3& radius(const double r) { // <> Statt r1() und r2() hat Circle_3 nun die sinnvolle Elementfunktion radius()
        mEllipse.r1(r).r2(r); return *this;
    }
private:
    Ellipse_2 mEllipse; // <> Komposition
};

void test3() {
    std::vector<std::unique_ptr<Shape>> v; // <> Verwendung der Schnittstelle Shape
    v.push_back(std::make_unique<Circle_3>(10.0));
    v.push_back(std::make_unique<Ellipse_1>(10.0, 20.0));
    
    Canvas canvas;
    for(const auto& e : v) {
        e->draw(canvas);
    }
}

// Weitere Lösungsmöglichkeiten:

// Ansatz 4:
// Fehlschlagen unsinniger Operationen
// Nachteil: Verantwortung hat der Aufrufer
// Nachteil: Basisklasse muss dafür vorbereitet sein
struct Ellipse_20 : public Shape {
    Ellipse_20(const double r1, const double r2) : mR1{r1}, mR2{r2} {}
    virtual void draw(Canvas&) const override {printf("draw E20(%g,%g)\n", mR1, mR2);}
    [[nodiscard]] virtual bool r1(const double r) {mR1 = r; return true;}
    [[nodiscard]] virtual bool r2(const double r) {mR2 = r; return true;}
    double area() const {return mR1 * mR2 * std::numbers::pi_v<double>;}
protected:
    double mR1{0};
    double mR2{0};
};
struct Circle_20 : public Ellipse_20 { // Sub-Classing
    Circle_20(const double r) : Ellipse_20{r, r} {}
    virtual void draw(Canvas&) const {printf("draw C20(%g)\n", mR1);}
    [[nodiscard]] virtual bool r1(const double r) {mR1 = mR2 = r; return true;}
    [[nodiscard]] virtual bool r2(const double) {return false;}
};

// Ansatz 5:
// Umkehr der Vererbungbeziehung
// Nachteil: mathematisch unsinnig

// Ansatz 6:
// Verzicht auf Klasse Circle, stattdessen Beobachter isCircle() in Klasse Ellipse
// Nachteil: Unterscheidung zwischen Kreis und Ellipse findet sich nicht (statisch) in der Schnittstelle wieder, sondern muss zur Laufzeit geprüft werden.

// Nicht adressierte Probleme:
// 1: Vererbung ist statisch (compile-time)
// 2: Vererbung ergibt engste Koppelung
// 3: Vererbung entkapselt protected Datenelemente

// Weitere Bemerkungen:
// 1: Komposition kann via dependency-injection dynamisch sein
// 2: Komposition schafft auch eine Koppelung, die kann aber durch Einführung eines entsprechenden Interfaces für das/die Datenelement(e) wieder reduziert werden (DIP)
// 3: Komposition verletzt die Kapselung nicht
// 4: Komposition kann eine Alternative zu Mehrfachvererbung (ohne deren Probleme) sein.
// 5: Komposition ist auch Code-Wiederverwendung, allerdings mit moderatem Overhead für Delegation

int main() {
    test1();
    
    Circle_2 c1{10.0};    
    test2(c1);
    
    test3();    
}
