static const char basicWebsite[] PROGMEM = "<!DOCTYPE html>\
<html>\
    <head>\
        <title>WLAN-Einrichtung</title>\
    </head>\
    <body>\
        <form action=\"/init\" method=\"POST\">\
            <fieldset>\
                <legend>Initiale WLAN-Einrichtung</legend>\
                <label for=\"ssid\">SSID:</label><br>\
                <input type=\"text\" id=\"ssid\" name=\"ssid\" placeholder=\"SSID\" required><br>\
                <label for=\"pwd\">Passwort:</label><br>\
                <input type=\"password\" id=\"pwd\" name=\"pwd\" autocomplete=\"off\" required><br>\
                <label for=\"hostname\">Tonuino-Name (Hostname):</label><br>\
                <input type=\"text\" id=\"hostname\" name=\"hostname\" required><br><br>\
                <input type=\"submit\" value=\"Absenden\">\
            </fieldset>\
        </form>\
        <form action=\"/restart\">\
            <button type=\"submit\">Neustart</button>\
        </form>\
    </body>\
</html>\
";
