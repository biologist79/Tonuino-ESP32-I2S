static const char mgtWebsite[] PROGMEM = "<!DOCTYPE html>\
<html lang=\"de\">\
  <head>\
    <title>ESPuino-Konfiguration</title>\
    <meta charset=\"utf-8\">\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
    <link rel=\"stylesheet\" href=\"https://ts-cs.de/tonuino/css/bootstrap.min.css\">\
    <link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/jstree/3.2.1/themes/default/style.min.css\" />\
    <link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.1/css/all.min.css\"/>\
    <link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/toastr.js/latest/toastr.min.css\" />\
    <script src=\"https://ts-cs.de/tonuino/js/jquery.min.js\"></script>\
    <script src=\"https://code.jquery.com/ui/1.12.0/jquery-ui.min.js\" integrity=\"sha256-eGE6blurk5sHj+rmkfsGYeKyZx3M4bG+ZlFyA7Kns7E=\" crossorigin=\"anonymous\"></script>\
    <script src=\"https://ts-cs.de/tonuino/js/popper.min.js\"></script>\
    <script src=\"https://ts-cs.de/tonuino/js/bootstrap.min.js\"></script>\
    <script src=\"https://cdnjs.cloudflare.com/ajax/libs/jstree/3.2.1/jstree.min.js\"></script>\
    <script src=\"https://cdnjs.cloudflare.com/ajax/libs/toastr.js/latest/toastr.min.js\"></script>\
    <style type=\"text/css\">\
      .filetree {\
        border: 1px solid black;\
        margin: 0em 0em 1em 0em;\
        height: 200px;\
        overflow-y: scroll;\
      }\
      .fa-sync:hover{\
        color: #666666;\
      }\
    </style>\
  </head>\
  <body>\
    <nav class=\"navbar navbar-expand-sm bg-primary navbar-dark\">\
      <button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\
        <span class=\"navbar-toggler-icon\"></span>\
      </button>\
      <a class=\"navbar-brand\">\
        <img src=\"https://raw.githubusercontent.com/biologist79/Tonuino-ESP32-I2S/master/html/tonuino_logo.png\" width=\"30\" height=\"30\" class=\"d-inline-block align-top\" alt=\"\" />\
        Tonuino\
      </a>\
      <div class=\"collapse navbar-collapse\" id=\"collapsibleNavbar\">\
        <ul class=\"navbar-nav mr-auto\">\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"#wifiConfig\">WLAN</a>\
          </li>\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"#rfidMusicTags\">RFID-Zuweisungen</a>\
          </li>\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"#rfidModTags\">RFID-Modifikationen</a>\
          </li>\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"#mqttConfig\">MQTT</a>\
          </li>\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"#ftpConfig\">FTP</a>\
          </li>\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"#generalConfig\">Allgemein</a>\
          </li>\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"#importNvs\">NVS-Importer</a>\
          </li>\
          <li class=\"nav-item\">\
            <a class=\"nav-link\" href=\"/restart\" style=\"color: orange\">Neustart Tonuino</a>\
          </li>\
        </ul>\
      </div>\
    </nav>\
    <br />\
    <div class=\"container\" id=\"wifiConfig\">\
      <h2>WLAN-Konfiguration</h2>\
      <form action=\"#wifiConfig\" method=\"POST\" onsubmit=\"wifiConfig('wifiConfig'); return false\">\
        <div class=\"form-group col-md-6\">\
          <label for=\"ssid\">WLAN-Name (SSID):</label>\
          <input type=\"text\" class=\"form-control\" id=\"ssid\" placeholder=\"SSID\" name=\"ssid\" required>\
          <div class=\"invalid-feedback\">\
            Bitte SSID des WLANs eintragen.\
          </div>\
          <label for=\"pwd\">Passwort:</label>\
          <input type=\"password\" class=\"form-control\" id=\"pwd\" placeholder=\"Passwort\" name=\"pwd\" required>\
          <label for=\"hostname\">Tonuino-Name (Hostname):</label>\
          <input type=\"text\" class=\"form-control\" id=\"hostname\" placeholder=\"tonuino\" name=\"hostname\" value=\"%HOSTNAME%\" pattern=\"^[^-\\.]{2,32}\" required>\
        </div>\
        <button type=\"reset\" class=\"btn btn-secondary\">Reset</button>\
        <button type=\"submit\" class=\"btn btn-primary\">Absenden</button>\
      </form>\
      <div class=\"messages col-md-6 my-2\"></div>\
    </div>\
    <div class=\"container my-5\" id=\"rfidMusicTags\">\
        <h2>RFID-Zuweisungen</h2>\
        <form action=\"#rfidMusicTags\" method=\"POST\" onsubmit=\"rfidAssign('rfidMusicTags'); return false\">\
            <div class=\"form-group col-md-6\">\
                <label for=\"rfidIdMusic\">RFID-Chip-Nummer (12-stellig)</label>\
                <input type=\"text\" class=\"form-control\" id=\"rfidIdMusic\" maxlength=\"12\" pattern=\"[0-9]{12}\" placeholder=\"%RFID_TAG_ID%\" name=\"rfidIdMusic\" required>\
                <label for=\"fileOrUrl\">Datei, Verzeichnis oder URL (^ und # als Zeichen nicht erlaubt)</label>\
                <input type=\"text\" class=\"form-control\" id=\"fileOrUrl\" maxlength=\"255\" placeholder=\"z.B. /mp3/Hoerspiele/Yakari/Yakari_und_seine_Freunde.mp3\" pattern=\"^[^\\^#]+$\" name=\"fileOrUrl\" required>\
                <div id=\"filebrowser\">\
                  <div class=\"filetree demo\" id=\"filetree\"></div>\
                  <div style=\"width:100%; margin-botton:1em; text-align: right; font-size: 0.8em;\">\
                      <span id=\"refreshAction\" data-toggle=\"tooltip\" data-placement=\"top\" title=\"Datei Liste aktualisieren.\"><i class=\"fas fa-sync fa-1x\"></i></span>\
                  </div>\
                </div>\
                <label for=\"playMode\">Abspielmodus</label>\
                <select class=\"form-control\" id=\"playMode\" name=\"playMode\">\
                    <option value=\"1\">Einzelner Titel</option>\
                    <option value=\"2\">Einzelner Titel (Endlosschleife)</option>\
                    <option value=\"3\">Hörbuch</option>\
                    <option value=\"4\">Hörbuch (Endlosschleife)</option>\
                    <option value=\"5\">Alle Titel eines Verzeichnis (sortiert)</option>\
                    <option value=\"6\">Alle Titel eines Verzeichnis (zufällig)</option>\
                    <option value=\"7\">Alle Titel eines Verzeichnis (sortiert, Endlosschleife)</option>\
                    <option value=\"9\">Alle Titel eines Verzeichnis (zufällig, Endlosschleife)</option>\
                    <option value=\"8\">Webradio</option>\
                </select>\
            </div>\
          <button type=\"reset\" class=\"btn btn-secondary\">Reset</button>\
          <button type=\"submit\" class=\"btn btn-primary\">Absenden</button>\
        </form>\
        <div class=\"messages col-md-6 my-2\"></div>\
    </div>\
    <div class=\"container my-5\" id=\"rfidModTags\">\
        <h2>RFID-Modifkationen</h2>\
        <form class=\"needs-validation\" action=\"#rfidModTags\" method=\"POST\" onsubmit=\"rfidMods('rfidModTags'); return false\">\
            <div class=\"form-group col-md-6\">\
                <label for=\"rfidIdMod\">RFID-Chip-Nummer (12-stellig)</label>\
                <input type=\"text\" class=\"form-control\" id=\"rfidIdMod\" maxlength=\"12\" pattern=\"[0-9]{12}\" placeholder=\"%RFID_TAG_ID%\" name=\"rfidIdMod\" required>\
                <div class=\"invalid-feedback\">\
                  Bitte eine 12-stellige Zahl eingeben.\
                </div>\
                <label for=\"modId\">Abspielmodus</label>\
                <select class=\"form-control\" id=\"modId\" name=\"modId\">\
                    <option value=\"100\">Tastensperre</option>\
                    <option value=\"101\">Schlafen nach 15 Minuten</option>\
                    <option value=\"102\">Schlafen nach 30 Minuten</option>\
                    <option value=\"103\">Schlafen nach 1 Stunde</option>\
                    <option value=\"104\">Schlafen nach 2 Stunden</option>\
                    <option value=\"105\">Schlafen nach Ende des Titels</option>\
                    <option value=\"106\">Schlafen nach Ende der Playlist</option>\
                    <option value=\"107\">Schlafen nach fünf Titeln</option>\
                    <option value=\"110\">Wiederhole Playlist (endlos)</option>\
                    <option value=\"111\">Wiederhole Titel (endlos)</option>\
                    <option value=\"112\">Dimme LEDs (Nachtmodus)</option>\
                    <option value=\"130\">Aktiviere/deaktive WLAN</option>\
                </select>\
          </div>\
          <button type=\"reset\" class=\"btn btn-secondary\">Reset</button>\
          <button type=\"submit\" class=\"btn btn-primary\">Absenden</button>\
        </form>\
        <div class=\"messages col-md-6 my-2\"></div>\
    </div>\
    <div class=\"container my-5\" id=\"mqttConfig\">\
        <h2>MQTT-Konfiguration</h2>\
        <form class=\"needs-validation\" action=\"#mqttConfig\" method=\"POST\" onsubmit=\"mqttSettings('mqttConfig'); return false\">\
            <div class=\"form-check col-md-6\">\
                <input class=\"form-check-input\" type=\"checkbox\" value=\"1\" id=\"mqttEnable\" name=\"mqttEnable\" %MQTT_ENABLE%>\
                <label class=\"form-check-label\" for=\"mqttEnable\">\
                  MQTT aktivieren\
                </label>\
            </div>\
            <div class=\"form-group my-2 col-md-6\">\
                <label for=\"mqttServer\">MQTT-Server</label>\
                <input type=\"text\" class=\"form-control\" id=\"mqttServer\" minlength=\"7\" maxlength=\"%MQTT_SERVER_LENGTH%\" placeholder=\"z.B. 192.168.2.89\" name=\"mqttServer\" value=\"%MQTT_SERVER%\">\
                <label for=\"mqttUser\">MQTT-Benutzername (optional):</label>\
                <input type=\"text\" class=\"form-control\" id=\"mqttUser\" maxlength=\"%MQTT_USER_LENGTH%\" placeholder=\"Benutzername\" name=\"mqttUser\" value=\"%MQTT_USER%\">\
                <label for=\"mqttPwd\">Passwort (optional):</label>\
                <input type=\"password\" class=\"form-control\" id=\"mqttPwd\" maxlength=\"%MQTT_PWD_LENGTH%\" placeholder=\"Passwort\" name=\"mqttPwd\" value=\"%MQTT_PWD%\">\
            </div>\
          <button type=\"reset\" class=\"btn btn-secondary\">Reset</button>\
          <button type=\"submit\" class=\"btn btn-primary\">Absenden</button>\
        </form>\
        <div class=\"messages col-md-6 my-2\"></div>\
    </div>\
    <div class=\"container\" id=\"ftpConfig\">\
        <h2>FTP-Konfiguration</h2>\
        <form action=\"#ftpConfig\" method=\"POST\" onsubmit=\"ftpSettings('ftpConfig'); return false\">\
          <div class=\"form-group col-md-6\">\
            <label for=\"ftpUser\">FTP-Benutzername:</label>\
            <input type=\"text\" class=\"form-control\" id=\"ftpUser\" maxlength=\"%FTP_USER_LENGTH%\" placeholder=\"Benutzername\" name=\"ftpUser\" value=\"%FTP_USER%\" required>\
            <label for=\"pwd\">Passwort:</label>\
            <input type=\"password\" class=\"form-control\" id=\"ftpPwd\" maxlength=\"%FTP_PWD_LENGTH%\" placeholder=\"Passwort\" name=\"ftpPwd\" value=\"%FTP_PWD%\" required>\
          </div>\
          <button type=\"reset\" class=\"btn btn-secondary\">Reset</button>\
          <button type=\"submit\" class=\"btn btn-primary\">Absenden</button>\
        </form>\
        <div class=\"messages col-md-6 my-2\"></div>\
    </div>\
    <div class=\"container my-5\" id=\"generalConfig\">\
        <h2>Allgemeine Konfiguration</h2>\
        <form action=\"#generalConfig\" method=\"POST\" onsubmit=\"genSettings('generalConfig'); return false\">\
            <div class=\"form-group col-md-6\">\
                <label for=\"initialVolume\">Lautstärke nach dem Einschalten</label>\
                <input type=\"number\" min=\"1\" max=\"21\" class=\"form-control\" id=\"initialVolume\" name=\"initialVolume\" value=\"%INIT_VOLUME%\" required>\
                <label for=\"maxVolumeSpeaker\">Maximale Lautstärke (Lautsprecher)</label>\
                <input type=\"number\" min=\"1\" max=\"21\" class=\"form-control\" id=\"maxVolumeSpeaker\" name=\"maxVolumeSpeaker\" value=\"%MAX_VOLUME_SPEAKER%\" required>\
                <label for=\"maxVolumeHeadphone\">Maximale Lautstärke (Kopfhörer)</label>\
                <input type=\"number\" min=\"1\" max=\"21\" class=\"form-control\" id=\"maxVolumeHeadphone\" name=\"maxVolumeHeadphone\" value=\"%MAX_VOLUME_HEADPHONE%\" required>\
            </div>\
            <div class=\"form-group col-md-6\">\
                <label for=\"initBrightness\">Neopixel-Helligkeit nach dem Einschalten</label>\
                <input type=\"number\" min=\"0\" max=\"255\" class=\"form-control\" id=\"initBrightness\" name=\"initBrightness\" value=\"%INIT_LED_BRIGHTNESS%\" required>\
                <label for=\"nightBrightness\">Neopixel-Helligkeit im Nachtmodus</label>\
                <input type=\"number\" min=\"0\" max=\"255\" class=\"form-control\" id=\"nightBrightness\" name=\"nightBrightness\" value=\"%NIGHT_LED_BRIGHTNESS%\" required>\
            </div>\
            <div class=\"form-group col-md-6\">\
                <label for=\"inactivityTime\">Deep-Sleep nach Inaktivität (Minuten)</label>\
                <input type=\"number\" min=\"1\" max=\"1440\" class=\"form-control\" id=\"inactivityTime\" name=\"inactivityTime\" value=\"%MAX_INACTIVITY%\" required>\
            </div>\
          <button type=\"reset\" class=\"btn btn-secondary\">Reset</button>\
          <button type=\"submit\" class=\"btn btn-primary\">Absenden</button>\
        </form>\
        <div class=\"messages col-md-6 my-2\"></div>\
      </div>\
      <div class=\"container my-5\" id=\"importNvs\">\
        <h2>NVS-Importer</h2>\
        <form action=\"/upload\" enctype=\"multipart/form-data\" method=\"POST\">\
          <div class=\"form-group\">\
            <label for=\"nvsUpload\">Hier kann eine Backup-Datei importiert werden.</label>\
            <input type=\"file\" class=\"form-control-file\" id=\"nvsUpload\" name=\"nvsUpload\" accept=\".txt\">\
          </div>\
            <button type=\"submit\" class=\"btn btn-primary\">Absenden</button>\
        </form>\
        <div class=\"messages col-md-6 my-2\"></div>\
      </div>\
        <script type=\"text/javascript\">\
\
  \
        $(function () {\
            $('[data-toggle=\"tooltip\"]').tooltip();\
        });\
\
        toastr.options = {\
            \"closeButton\": false,\
            \"debug\": false,\
            \"newestOnTop\": false,\
            \"progressBar\": false,\
            \"positionClass\": \"toast-top-right\",\
            \"preventDuplicates\": false,\
            \"onclick\": null,\
            \"showDuration\": \"300\",\
            \"hideDuration\": \"1000\",\
            \"timeOut\": \"5000\",\
            \"extendedTimeOut\": \"1000\",\
            \"showEasing\": \"swing\",\
            \"hideEasing\": \"linear\",\
            \"showMethod\": \"fadeIn\",\
            \"hideMethod\": \"fadeOut\"\
        };\
\
        function postRendering(event, data){\
              Object.keys(data.instance._model.data).forEach(function(key,index) {\
           \
                  var cur = data.instance.get_node(data.instance._model.data[key]);\
                  var lastFolder = cur['id'].split('/').filter(function(el) { \
                        return el.trim().length > 0; \
                  }).pop();\
                  if ((/\\.(mp3|MP3|ogg|wav|WAV|OGG|wma|WMA|acc|ACC|flac|FLAC)$/i).test(lastFolder)){           \
                        data.instance.set_type(data.instance._model.data[key], 'audio');\
                  } else {\
                      if (data.instance._model.data[key]['type'] == \"file\"){\
                         data.instance.disable_node(data.instance._model.data[key]);\
                      }\
                  }\
                  data.instance.rename_node(data.instance._model.data[key], lastFolder);\
              });\
        }\
\
        function renderFileTree(){\
          $('#filetree').jstree({\
            'core' : {\
              'check_callback': true,\
              'data' : \
              {\
                url: \"/files\"\
              }\
            },\
            'types' : {\
                'folder' : {\
                   'icon' : \"fa fa-folder\"\
                },\
                'file' : {\
                  'icon': \"fa fa-file\"\
                },\
                'audio' : {\
                  'icon' : \"fa fa-file-audio\"\
                },\
                'default' : {\
                  'icon' : \"fa fa-folder\"\
                }\
              },\
            'plugins' : [ \"themes\", \"types\" ]\
          }).bind('loaded.jstree', function (event, data) {\
                postRendering(event, data);\
           }).bind('refresh.jstree',function (event, data) {\
                postRendering(event, data);\
           });\
          }\
          renderFileTree();\
\
          $('#filetree').on('select_node.jstree', function (e, data) { \
                $('input[name=fileOrUrl]').val(data.node.id);\
          });\
\
          $('#refreshAction').on(\"click\", function() {\
             refreshFileList();\
              $(\"#refreshAction i\").addClass(\"fa-spin\");\
          });\
\
          $('#playMode').on(\"change\", function () {\
            if (this.value == 8){\
              $('#filebrowser').slideUp();\
            }  else {\
              $('#filebrowser').slideDown();\
            }\
          });\
          var lastIdclicked = '';\
  \
          var socket = new WebSocket(\"ws://%IPv4%/ws\");\
\
          function connect() {\
            socket = new WebSocket(\"ws://%IPv4%/ws\");\
          }\
\
          function ping() {\
            var myObj = {\
              \"ping\": {\
                ping: 'ping'\
              }\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
            tm = setTimeout(function () {\
              toastr.warning('Die Verbindung zum Tonuino ist unterbrochen! Bitte Seite neu laden.');\
              }, 5000);\
          }\
\
          function pong() {\
            clearTimeout(tm);\
          }\
\
          socket.onopen = function () {\
            setInterval(ping, 15000);\
          };\
\
          socket.onclose = function(e) {\
            console.log('Socket is closed. Reconnect will be attempted in 1 second.', e.reason);\
            setTimeout(function() {\
              connect();\
            }, 5000);\
          };\
\
          socket.onerror = function(err) {\
            console.error('Socket encountered error: ', err.message, 'Closing socket');\
            socket.close();\
          };\
\
          socket.onmessage = function(event) {\
            console.log(event.data);\
            var socketMsg = JSON.parse(event.data);\
            console.log(socketMsg);\
            if (\"rfidId\" in socketMsg) {\
              $('#rfidIdMod').val(socketMsg.rfidId);\
              $(\"#rfidIdMusic\").val(socketMsg.rfidId);\
\
              toastr.info(\"RFID Tag mit \"+ socketMsg.rfidId + \" erkannt.\" );\
              \
              $(\"#rfidIdMusic\").effect(\"highlight\", {color:\"#abf5af\"}, 3000);\
              $(\"#rfidIdMod\").effect(\"highlight\", {color:\"#abf5af\"}, 3000);\
              \
\
            } if (\"status\" in socketMsg) {\
                \
                if (socketMsg.status == 'ok') {\
                  toastr.success(\"Aktion erfolgreich ausgeführt.\" );\
                } else {\
                  toastr.error(\"Es ist ein Fehler aufgetreten.\" );\
                }\
            } if (\"pong\" in socketMsg) {\
                if (socketMsg.pong == 'pong') {\
                  pong();\
                }\
            } if (\"refreshFileList\" in socketMsg){\
                toastr.info(\"Die Datei Liste wurde neu erzeugt!\");\
                $(\"#refreshAction i\").removeClass(\"fa-spin\");\
                $('#filetree').jstree(true).refresh();\
            }\
          };\
\
          function genSettings(clickedId) {\
            lastIdclicked = clickedId;\
            var myObj = {\
              \"general\": {\
                iVol: document.getElementById('initialVolume').value,\
                mVolSpeaker: document.getElementById('maxVolumeSpeaker').value,\
                mVolHeadphone: document.getElementById('maxVolumeHeadphone').value,\
                iBright: document.getElementById('initBrightness').value,\
                nBright: document.getElementById('nightBrightness').value,\
                iTime: document.getElementById('inactivityTime').value\
              }\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
          };\
\
          function refreshFileList(clickedId){\
            lastIdclicked = clickedId;\
            var myObj = {\
                \"refreshFileList\": true\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
          };\
          \
\
          function ftpSettings(clickedId) {\
            lastIdclicked = clickedId;\
            var myObj = {\
              \"ftp\": {\
                ftpUser: document.getElementById('ftpUser').value,\
                ftpPwd: document.getElementById('ftpPwd').value\
              }\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
          };\
\
          function mqttSettings(clickedId) {\
            lastIdclicked = clickedId;\
            var val;\
            if (document.getElementById('mqttEnable').checked) {\
              val = document.getElementById('mqttEnable').value;\
            } else {\
              val = 0;\
            }\
            var myObj = {\
              \"mqtt\": {\
                mqttEnable: val,\
                mqttServer: document.getElementById('mqttServer').value,\
                mqttUser: document.getElementById('mqttUser').value,\
                mqttPwd: document.getElementById('mqttPwd').value\
              }\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
          };\
\
          function rfidMods(clickedId) {\
            lastIdclicked = clickedId;\
            var myObj = {\
              \"rfidMod\": {\
                rfidIdMod: document.getElementById('rfidIdMod').value,\
                modId: document.getElementById('modId').value\
              }\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
          };\
\
          function removeTrSlash(str) {\
            if(str.substr(-1) === '/') {\
              return str.substr(0, str.length - 1);\
            }\
              return str;\
          };\
\
          function rfidAssign(clickedId) {\
            lastIdclicked = clickedId;\
            var myObj = {\
              \"rfidAssign\": {\
                rfidIdMusic: document.getElementById('rfidIdMusic').value,\
                fileOrUrl: removeTrSlash(document.getElementById('fileOrUrl').value),\
                playMode: document.getElementById('playMode').value\
              }\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
          };\
\
          function wifiConfig(clickedId) {\
            lastIdclicked = clickedId;\
            var myObj = {\
              \"wifiConfig\": {\
                ssid: document.getElementById('ssid').value,\
                pwd: document.getElementById('pwd').value,\
                hostname: document.getElementById('hostname').value\
              }\
            };\
            var myJSON = JSON.stringify(myObj);\
            socket.send(myJSON);\
          };\
        </script>\
  </body>\
</html>\
";