## Nr. 1a)
### Akteure:
 - User
 - Guest User

### Use-Cases:
#### Anmelden:
 - Login
 - Registrieren

#### Post Erstellen:
 - Post erstellen
 - Bild upload
    - Alt Text
 - Titel
 - Beschreibung
 - Hashtags
 - Links
 - Post Veröffentlichen
 - Benachrichtigung senden

#### Post Interaktion:
 - Bookmark
 - Kommentieren
 - Bild Downloaden

#### Profil einsehen:
 - Profil einsehen
 - Bookmarks einsehen
 - Posthistorie einsehen
 - Folgen
 - Profil Einstellungen
 - Profil Bearbeiten

#### Sonstiges:
 - Suche

## Nr. 1 b)
![Diagram Fotosoftware](Diagram_Fotosoftware.png)

## Nr. 1 c)

|||
|-|-|
|Name|Login|
|Nachbed. im Erfolgsfall|User wird angemeldet|
|Nachbed. bei Fehlschlag|Aufforderung zur neueingabe der Credentials|
|Akteur/e|User|
|Auslösendes Ereignis|User klickt Button|
|Beschreibung|1. Nutzer gibt Email und Passwort ein <br> 2. Nutzer Schickt Credentials ab <br> 3. Nutzer ist Angemeldet|
|Erweiterungen/Alternativen|1. Schließen der Login Maske <br> 2. Weiterleitung zur Registirerung|

|||
|-|-|
|Name|Registrieren|
|Nachbed. im Erfolgsfall| 1. Anmeldeverfahren wird durchlaufen <br> 2. Userkonto wurde erstellt und User ist nun angemeldet|
|Nachbed. bei Fehlschlag| Erromeldung mit Ereigniscode und Kurz-Beschreibung|
|Akteur/e|Guest User|
|Auslösendes Ereignis|Guest User Klickt Button|
|Beschreibung|1. Der Nutzer gibt einen @ seiner Wahl ein <br> 2. Nutzer gibt Email Adresse ein <br> 3. Nutzer gibt Passwort ein <br> 4. Nutzer klickt auf beenden|
|Erweiterungen/Alternativen|1. Abbrechen|

<br>

|||
|-|-|
|Name|Post erstellen|
|Nachbed. im Erfolgsfall|Eine Maske für das erstellen eines neuen Posts öffnet|
|Nachbed. bei Fehlschlag|Popup-Fehlermeldung mit "Da ist etwas schief gelaufen :/"|
|Akteur/e|User|
|Auslösendes Ereignis|Klick auf den Button "Neuen Post erstellen"|
|Beschreibung|Eine Maske für das erstellen eines neuen Posts mit den Unterkategorien Bild upload-Alt Text, Titel, Beschreibung, Hashtag, Links, Post Veröffentlichung|
|Erweiterungen/Alternativen|Benachrichtigung Senden|

|||
|-|-|
|Name|Bild Upload|
|Nachbed. im Erfolgsfall|Bild wurder erfolgreich hochgeladen|
|Nachbed. bei Fehlschlag|Popup Fehlermeldung "Beim Hochladen des Bildes ist etwas schief gelaufen :/"|
|Akteur/e|User|
|Auslösendes Ereignis|Anwählen der Schalffläche "Bild hochladen" (Button, Drag and Drop Menu)|
|Beschreibung|1a. Bild über Drag & drop Menu ziehen <br> 1b. Klicklen des "Datei auswählen" Buttons|
|Erweiterungen/Alternativen|1. Weiteres Bild hochladen <br> 2. Alt Text hinzufügen  <br> "Content Warning" Hinzufügen (Blured das Bild im Feed falls es NSFW ist)|

|||
|-|-|
|Name|Titel|
|Nachbed. im Erfolgsfall|Post wurde ein erfolgreich ein Titel hinzugefügt|
|Nachbed. bei Fehlschlag|Popup-Fehlermeldung mit "Da ist etwas schief gelaufen :/"|
|Akteur/e|User|
|Auslösendes Ereignis|Klick auf die Textfeld "Titel hinzufügen"|
|Beschreibung|1. Nutzer klickt auf Textfeld <br> 2. Titel einfügen <br> 3. Speichern|
|Erweiterungen/Alternativen|-|

|||
|-|-|
|Name|Beschreibung|
|Nachbed. im Erfolgsfall|Post wurde ein erfolgreich eine Beschreibung hinzugefügt|
|Nachbed. bei Fehlschlag|Popup-Fehlermeldung mit "Da ist etwas schief gelaufen :/"|
|Akteur/e|User|
|Auslösendes Ereignis|Klick auf das Textfeld "Beschreibung hinzufügen"|
|Beschreibung|1. Nutzer klickt auf Textfeld <br> 2. Beschreibung einfügen <br> 3. Speichern|
|Erweiterungen/Alternativen|-|

|||
|-|-|
|Name|Hashtags|
|Nachbed. im Erfolgsfall|Post wurde erfolgreich ein/mehrere Hashtags hinzugefügt|
|Nachbed. bei Fehlschlag|Popup-Fehlermeldung mit "Da ist etwas schief gelaufen :/"|
|Akteur/e|User|
|Auslösendes Ereignis|Klick auf das Feld "Hashtag hinzufügen"|
|Beschreibung|1. Nutzer klickt auf Feld <br> 2a. Hashtag auswählen und hinzufühen <br> 2b. Neuen Hashtag hinzufügen <br> 3. Speichern|
|Erweiterungen/Alternativen|-|


|||
|-|-|
|Name|Links|
|Nachbed. im Erfolgsfall|Post wurde erfolgreich ein/mehrere Links hinzugefügt|
|Nachbed. bei Fehlschlag|Popup-Fehlermeldung mit "Da ist etwas schief gelaufen :/"|
|Akteur/e|User|
|Auslösendes Ereignis|Klick auf das Textfeld "Links hinzufügen"|
|Beschreibung|1. Nutzer klickt auf Textfeld <br> 2. Links mit Substitute einfügen <br> 3. Speichern|
|Erweiterungen/Alternativen|-|

|||
|-|-|
|Name|Post veröfentlichen|
|Nachbed. im Erfolgsfall|1. Post wird hochgeladen <br> 2. Benachrichtigugn an Follower des Users werden gesendet|
|Nachbed. bei Fehlschlag|1. Popup-Fehlermeldung mit "Da ist etwas schief gelaufen :/ <br> 2. Aufblinken eines Verpflichtenden Feldes das leer ist <br> 3. Evtl. Meldung popt auf "Post wurde als Enwurf gespeichert"|
|Akteur/e|User|
|Auslösendes Ereignis|Klicken des Buttons "Post veröffentlichen"|
|Beschreibung|User klickt Button|
|Erweiterungen/Alternativen|1. User bricht Post ab und verwirfft änderungen <br> 2. User Speichert Post als Entwurf|

|||
|-|-|
|Name|Benachrichtigung senden|
|Nachbed. im Erfolgsfall|Eine Benachrichtigung wird an den Follower gesendet|
|Nachbed. bei Fehlschlag|1. Wiederholtes versuchen <br> 2. Bei eerneutem Scheitern Abbruch|
|Akteur/e|Atomatisiert|
|Auslösendes Ereignis|Anklick des "Post veröffentlichen" Buttons|
|Beschreibung|1. "Post veröffentlichen" wird geklickt <br> 2. Benachrichtigung mit Titel und Vorschaubild wird nach vorlage generiert <br> 3. Benachrichtigung wird an folgenden User gesendet|
|Erweiterungen/Alternativen|-|
<br> <br>

|||
|-|-|
|Name|Post Interaktionen|
|Nachbed. im Erfolgsfall|1. User hat mit dem Post interagiert <br> 2. Statistik Werte des Post updaten sich (Bookmarks, Views, Kommentare)|
|Nachbed. bei Fehlschlag|1. Server Error wird angezeigt "Post konnte nicht geladen werden" <br> 2. Objekte werden neu gerendert um werte zu updaten|
|Akteur/e|User|
|Auslösendes Ereignis|Interaktion mit einer der Schaltflächgen "Kommentar", "Bookmark", "Post einsehen"|
|Beschreibung|1. User Klickt Post an (Post einsehen) <br> 2a. User klickt "Kommentar" an <br> 2b. User klickt "Bookmark" an <br> 3. Werte (Bookmark anzahl, Kommentar anzahl) werden lokal um eins erhöht und neu gerendert.|
|Erweiterungen/Alternativen|-|

|||
|-|-|
|Name|Bookmark|
|Nachbed. im Erfolgsfall|Postid/Link wird unter dem Profil des Users gespeichert.|
|Nachbed. bei Fehlschlag|1. Aktion wird abgebrochen <br> 2. Post wird neu gerendert|
|Akteur/e|User|
|Auslösendes Ereignis|Klick auf den "Bookmark" Button|
|Beschreibung|1. Klick auf den "Bookmark" Button <br> 2a. List auswählen <br> 2b. Neue Liste erstellen und bnnenen <br> 3. Gespeichert Popupmeldung (Natives Android/IOs oder Web Popup) <br> 4. Gerenderter Bookmark wert with lokal um eins erhöht (verhindert neu rendern des ganzen posts)|
|Erweiterungen/Alternativen|-|

|||
|-|-|
|Name|Kommentieren|
|Nachbed. im Erfolgsfall|Neuer Kommentar wurde gespeichert|
|Nachbed. bei Fehlschlag|1. Bisher geschrieber Kommentar wird als Entwurf <br> 2. Post wurd neu gerentdert.|
|Akteur/e|User|
|Auslösendes Ereignis|1. Klick auf die Kommentar Zeile <br> 2. Klick auf den Antwort Button eines Kommentars|
|Beschreibung|1a. Klick auf die Kommentar Zeile <br> 1b. Klick auf die Antowrt Button <br> 2. Originat Post- /Kommentarerverfasser (OP) wird automatisch verlinkt <br> 2b. Alternativ andere User (mit ihrem @) verlinken <br> 4. Speichern/Senden Drücken <br> 4b. Kommentrar als Entwurf Speichern. <br> 5. Post wird neu geladen|
|Erweiterungen/Alternativen|-|

|||
|-|-|
|Name|BIld Download|
|Nachbed. im Erfolgsfall|1. Pop-up Meldung mit "Bild erfolgreich heruntergeldaden" <br> 2. Bild landet im, vom System, voreingestellten Downloads folder|
|Nachbed. bei Fehlschlag|Pop-up Meldung "Irgend etwas ist schief gelaufen "Absatz" Versuchen sie es später erneut"|
|Akteur/e|User|
|Auslösendes Ereignis|User Klickt auf "Bild Herunterladen" Button|
|Beschreibung|1. User klickt auf "Bild herunterladen" Button <br> 2a. Pop-up Meldung mit "Bild erfolgreich heruntergeldaden" <br> 2b. Pop-up Meldung "Irgend etwas ist schief gelaufen "Absatz" Versuchen sie es später erneut" <br> 3a. Bild erfolgreich Heruntergeladen <br> 3b. Abbruch|
|Erweiterungen/Alternativen|Evtl. Cool down für den Download des gleichen Bilds (verhindert doppelten download wenn User doppelt klickt)|

<br>

|||
|-|-|
|Name||
|Nachbed. im Erfolgsfall||
|Nachbed. bei Fehlschlag||
|Akteur/e||
|Auslösendes Ereignis||
|Beschreibung||
|Erweiterungen/Alternativen||

|||
|-|-|
|Name||
|Nachbed. im Erfolgsfall||
|Nachbed. bei Fehlschlag||
|Akteur/e||
|Auslösendes Ereignis||
|Beschreibung||
|Erweiterungen/Alternativen||

|||
|-|-|
|Name||
|Nachbed. im Erfolgsfall||
|Nachbed. bei Fehlschlag||
|Akteur/e||
|Auslösendes Ereignis||
|Beschreibung||
|Erweiterungen/Alternativen||

|||
|-|-|
|Name||
|Nachbed. im Erfolgsfall||
|Nachbed. bei Fehlschlag||
|Akteur/e||
|Auslösendes Ereignis||
|Beschreibung||
|Erweiterungen/Alternativen||

|||
|-|-|
|Name||
|Nachbed. im Erfolgsfall||
|Nachbed. bei Fehlschlag||
|Akteur/e||
|Auslösendes Ereignis||
|Beschreibung||
|Erweiterungen/Alternativen||

#### Profil einsehen:
 - Profil einsehen
 - Bookmarks einsehen
 - Posthistorie einsehen
 - Folgen
 - Profil Einstellungen
 - Profil Bearbeiten

#### Sonstiges:
 - Suche