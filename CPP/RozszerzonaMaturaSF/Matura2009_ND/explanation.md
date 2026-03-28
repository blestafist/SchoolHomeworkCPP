# Wyjaśnienie Algorytmów - Matura 2009 Para Słów

## Zadanie A - Liczenie Palindromów

### Cel:
Policzyć ile słów (wszystkich, nie par) w pliku `dane.txt` jest palindromami.

### Algorytm:
1. Wczytujemy każde słowo z pliku `dane.txt` (dwa słowa z każdego wiersza)
2. Dla każdego słowa sprawdzamy czy jest palindromem funkcją `IsPalindrome`
3. Zwiększamy licznik za każdy znaleziony palindrom
4. Zapisujemy wynik do `zad_5.txt`

### Funkcja `IsPalindrome`:
```cpp
bool IsPalindrome(const std::string& word) {
    for (size_t i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - 1 - i]) { return false; }
    }
    return true;
}
```

**Jak działa:**
- Iterujemy tylko do połowy długości słowa (optymalizacja)
- Porównujemy znak z początku (indeks `i`) ze znakiem z końca (indeks `size - 1 - i`)
- Jeśli którakolwiek para się nie zgadza → zwracamy `false`
- Jeśli wszystkie pary się zgadzają → zwracamy `true`

**Przykłady:**
- `10101` → porównujemy: pozycja 0 i 4 (`1==1` ✓), pozycja 1 i 3 (`0==0` ✓) → **palindrom**
- `10011` → porównujemy: pozycja 0 i 4 (`1==1` ✓), pozycja 1 i 3 (`0==1` ✗) → **nie palindrom**
- `11` → porównujemy: pozycja 0 i 1 (`1==1` ✓) → **palindrom**

**Wynik:** 46 palindromów

---

## Zadanie B - Sprawdzanie Zawierania

### Cel:
Policzyć ile par (A, B) ma właściwość, że słowo B jest zawarte wewnątrz słowa A.

### Algorytm:
1. Wczytujemy pary słów (A, B) z pliku
2. Dla każdej pary sprawdzamy czy B występuje jako podciąg w A
3. Zwiększamy licznik jeśli B jest zawarte w A
4. Zapisujemy wynik do `zad_5.txt` (z `std::ios::app` żeby dopisać)

### Funkcja `ContainsSubstring`:
```cpp
bool ContainsSubstring(const std::string& a, const std::string& b) {
    if (b.size() > a.size()) { return false; }
    
    size_t maxStartPos = a.size() - b.size() + 1;
    
    for (size_t i = 0; i < maxStartPos; i++) {
        bool found = true;
        for (size_t j = 0; j < b.size(); j++) {
            if (a[i + j] != b[j]) { found = false; break; }
        }
        if (found) { return true; }
    }
    
    return false;
}
```

**Jak działa:**
- Sprawdzamy wszystkie możliwe pozycje startowe w słowie A (od 0 do `a.size() - b.size()`)
- Dla każdej pozycji `i` porównujemy kolejne znaki B z fragmentem A zaczynając od pozycji `i`
- Jeśli wszystkie znaki się zgadzają → znaleziono dopasowanie, zwracamy `true`
- Jeśli żadna pozycja nie pasuje → zwracamy `false`

**Przykłady:**
- A = `10011101`, B = `111`
  - Pozycja 0: `100` ≠ `111`
  - Pozycja 1: `001` ≠ `111`
  - ...
  - Pozycja 4: `111` == `111` ✓ → **zawarte!**

- A = `1100001101`, B = `110`
  - Pozycja 0: `110` == `110` ✓ → **zawarte!**

**Wynik:** 35 par

---

## Zadanie C - Sklejenie Bez Nakładania

### Cel:
Policzyć ile par (A, B) ma właściwość, że **jedyną** możliwością utworzenia słowa C jest proste sklejenie (bez overlap).

### Algorytm:
1. Wczytujemy pary słów (A, B) z pliku
2. Dla każdej pary sprawdzamy dwa warunki:
   - B NIE jest zawarte w A (bo wtedy C = A, nie sklejenie)
   - NIE ma nakładania między słowami (bo wtedy możemy zoptymalizować)
3. Jeśli oba warunki spełnione → możliwe tylko sklejenie
4. Zapisujemy wynik do `zad_5.txt`

### Funkcja `HasOverlap`:
```cpp
bool HasOverlap(const std::string& a, const std::string& b) {
    // Sprawdzamy czy sufiks A = prefiks B
    for (int i = 1; i < (int)a.size(); i++) {
        size_t overlapLen = a.size() - i;
        if (overlapLen > b.size()) { continue; }
        
        bool matches = true;
        for (size_t j = 0; j < overlapLen; j++) {
            if (a[i + j] != b[j]) { matches = false; break; }
        }
        if (matches) { return true; }
    }
    
    // Sprawdzamy czy sufiks B = prefiks A
    for (int i = 1; i < (int)b.size(); i++) {
        size_t overlapLen = b.size() - i;
        if (overlapLen > a.size()) { continue; }
        
        bool matches = true;
        for (size_t j = 0; j < overlapLen; j++) {
            if (b[i + j] != a[j]) { matches = false; break; }
        }
        if (matches) { return true; }
    }
    
    return false;
}
```

**Jak działa:**
Sprawdza dwa scenariusze:

**Scenariusz 1: A + B z nakładaniem**
- Sprawdzamy czy końcówka A (sufiks) zgadza się z początkiem B (prefiks)
- Przykład: A=`10011`, B=`11000` → sufiks `11` = prefiks `11` ✓

**Scenariusz 2: B + A z nakładaniem**
- Sprawdzamy czy końcówka B (sufiks) zgadza się z początkiem A (prefiks)
- Przykład: A=`10011`, B=`1100` → sufiks `100` = prefiks `100` ✓

**Warunek "tylko sklejenie":**
- B NIE w A **AND** brak overlap → tylko sklejenie możliwe

**Przykład:**
- A = `10011101`, B = `000`
  - B nie jest w A ✓
  - Sufiks A (`1`, `01`, `101`, ...) ≠ Prefiks B (`0`, `00`, `000`)
  - Sufiks B (`0`, `00`, `000`) ≠ Prefiks A (`1`, `10`, `100`, ...)
  - Brak overlap ✓
  - **Wynik: możliwe tylko A+B lub B+A**

**Wynik:** 13 par

---

## Zadanie D - Tworzenie Najkrótszego Słowa C

### Cel:
Dla każdej pary (A, B) stworzyć najkrótsze słowo C, które zawiera oba słowa.

### Algorytm:
1. Wczytujemy pary słów (A, B) z pliku
2. Dla każdej pary znajdujemy najkrótsze C funkcją `FindShortestWord`
3. Zapisujemy każde C do pliku `slowa.txt` w osobnym wierszu

### Funkcja `FindShortestWord`:
```cpp
std::string FindShortestWord(const std::string& a, const std::string& b) {
    if (ContainsSubstring(a, b)) { return a; }
    
    std::string mergeAB = MergeWithOverlap(a, b);
    std::string mergeBA = MergeWithOverlap(b, a);
    
    if (mergeAB.size() <= mergeBA.size()) { return mergeAB; }
    else { return mergeBA; }
}
```

**Strategia:**

**Krok 1: Sprawdź czy B jest w A**
- Jeśli tak → C = A (najkrótsze możliwe)
- Przykład: A=`10011101`, B=`111` → C=`10011101`

**Krok 2: Wypróbuj obie kolejności z nakładaniem**
- Wariant 1: A → B (A na początku, B na końcu)
- Wariant 2: B → A (B na początku, A na końcu)
- Wybierz krótszy wynik

### Funkcja `MergeWithOverlap`:
```cpp
std::string MergeWithOverlap(const std::string& first, const std::string& second) {
    int maxOverlap = 0;
    
    // Szukamy najdłuższego overlap (sufiks first = prefiks second)
    for (int i = 1; i <= (int)first.size() && i <= (int)second.size(); i++) {
        bool matches = true;
        
        for (int j = 0; j < i; j++) {
            if (first[first.size() - i + j] != second[j]) {
                matches = false;
                break;
            }
        }
        
        if (matches) { maxOverlap = i; }
    }
    
    // Budujemy wynik: first + second[overlap:]
    std::string result = first;
    for (size_t i = maxOverlap; i < second.size(); i++) {
        result += second[i];
    }
    
    return result;
}
```

**Jak działa:**
1. Szukamy najdłuższego overlap (ile końcówka `first` zgadza się z początkiem `second`)
2. Iterujemy przez wszystkie możliwe długości overlap (1, 2, 3, ...)
3. Dla każdej długości `i` sprawdzamy czy ostatnie `i` znaków `first` = pierwsze `i` znaków `second`
4. Zapamiętujemy najdłuższy znaleziony overlap
5. Budujemy wynik: `first` + reszta `second` (pomijając overlap)

**Szczegółowy przykład:**

Wiersz 2: A = `1100001101`, B = `110`
- Krok 1: Czy B w A? TAK (na pozycji 0)
- **Wynik: C = `1100001101`**

Wiersz 4: A = `01101110`, B = `0001101`
- Krok 1: Czy B w A? NIE
- Krok 2a: MergeWithOverlap(A, B):
  - Overlap 1: A[-1:]=`0`, B[:1]=`0` → sprawdzamy czy pasuje: `0`==`0` ✓
  - Overlap 2: A[-2:]=`10`, B[:2]=`00` → `10`≠`00` ✗
  - maxOverlap = 1
  - Wynik: `01101110` + `001101` = `01101110001101` (14 znaków)
  
- Krok 2b: MergeWithOverlap(B, A):
  - Overlap 1: B[-1:]=`1`, A[:1]=`0` → `1`≠`0` ✗
  - Overlap 2: B[-2:]=`01`, A[:2]=`01` ✓
  - Overlap 3: B[-3:]=`101`, A[:3]=`011` ✗
  - Overlap 4: B[-4:]=`1101`, A[:4]=`0110` ✗
  - Overlap 5: B[-5:]=`01101`, A[:5]=`01101` ✓✓✓
  - maxOverlap = 5
  - Wynik: `0001101` + `110` = `0001101110` (10 znaków)
  
- **Wybieramy krótszy: `0001101110`**

Wiersz 8: A = `10`, B = `00`
- Krok 1: Czy B w A? NIE
- Krok 2a: MergeWithOverlap(A, B):
  - Overlap 1: A[-1:]=`0`, B[:1]=`0` ✓
  - maxOverlap = 1
  - Wynik: `10` + `0` = `100` (3 znaki)
  
- Krok 2b: MergeWithOverlap(B, A):
  - Overlap 1: B[-1:]=`0`, A[:1]=`1` ✗
  - maxOverlap = 0
  - Wynik: `00` + `10` = `0010` (4 znaki)
  
- **Wybieramy krótszy: `100`**

---

## Podsumowanie

### Złożoność czasowa:
- **Zadanie A:** O(n × m) gdzie n = liczba wszystkich słów (2×1000), m = długość słowa
- **Zadanie B:** O(n × |A| × |B|) gdzie n = liczba par
- **Zadanie C:** O(n × (|A| × |B| + |A|² + |B|²))
- **Zadanie D:** O(n × |A| × |B|)

### Wyniki:
- **a)** 46 palindromów
- **b)** 35 par gdzie B zawarte w A
- **c)** 13 par gdzie tylko sklejenie możliwe
- **d)** 1000 najkrótszych słów C w pliku `slowa.txt`
