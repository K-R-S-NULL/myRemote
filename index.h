const char MAIN_page[] PROGMEM = R"=====(
<HTML>
	<HEAD>
			<TITLE>MyRemote</TITLE>
            <STYLE>
                body {
                    background-color: #383b40;
                    color: #d3d3d3;
                }
                h1   {color: #d3d3d3;}
                p    {color: #d3d3d3;}
                .divTable{
                    display: table;
                    width: 90%;
                }
                .divTableRow {
                    display: table-row;
                }
                .divTableHeading {
                    background-color: #EEE;
                    display: table-header-group;
                }
                .divTableCell, .divTableHead {
                    display: table-cell;
                    padding: 3px 10px;
                }
                .divTableHeading {
                    background-color: #EEE;
                    display: table-header-group;
                    font-weight: bold;
                }
                .divTableFoot {
                    background-color: #EEE;
                    display: table-footer-group;
                    font-weight: bold;
                }
                .divTableBody {
                    display: table-row-group;
                }
                .centerCell {
                    text-align: center;
                    font-size:40px;
                }

                .myButton {
                    box-shadow:inset 0px 1px 3px 0px #91b8b3;
                    background:linear-gradient(to bottom, #768d87 5%, #6c7c7c 100%);
                    background-color:#768d87;
                    width: 85%;
                    border-radius:5px;
                    border:1px solid #566963;
                    display:inline-block;
                    cursor:pointer;
                    color:#ffffff;
                    font-family:Arial;
                    font-size:40px;
                    font-weight:bold;
                    padding:11px 23px;
                    text-decoration:none;
                    text-shadow:0px -1px 0px #2b665e;
                }
                .myButton:hover {
                    background:linear-gradient(to bottom, #6c7c7c 5%, #768d87 100%);
                    background-color:#6c7c7c;
                }
                .myButton:active {
                    position:relative;
                    top:1px;
                }
                .myButtonWakeUp {
                    box-shadow:inset 0px 1px 3px 0px #3e7327;
                    background:linear-gradient(to bottom, #77b55a 5%, #72b352 100%);
                    background-color:#77b55a;
                    border:1px solid #4b8f29;
                    color:#ffffff;
                    text-shadow:0px -1px 0px #5b8a3c;
                }
                .myButtonWakeUp:hover {
                    background:linear-gradient(to bottom, #72b352 5%, #77b55a 100%);
                    background-color:#72b352;
                }
                .myButtonStandby {
                    box-shadow:inset 0px 1px 3px 0px #b54b3a;
                    background:linear-gradient(to bottom, #a73f2d 5%, #b34332 100%);
                    background-color:#a73f2d;
                    border:1px solid #241d13;
                    color:#ffffff;
                    text-shadow:0px -1px 0px #7a2a1d;
                }
                .myButtonStandby:hover {
                    background:linear-gradient(to bottom, #b34332 5%, #a73f2d 100%);
                    background-color:#b34332;
                }
                
                .myButtonChannel {box-shadow:inset 0px 1px 3px 0px #f9eca0;
                    background:linear-gradient(to bottom, #a18300 5%, #f0d41f 100%);
                    background-color:#a18300;
                    border:1px solid #b38f00;
                    color:#454539;
                    text-shadow:0px -1px 0px #ded17c;
                }
                .myButtonChannel:hover {
                    background:linear-gradient(to bottom, #f0d41f 5%, #a18300 100%);
	                background-color:#f0d41f;
                }

                

            </STYLE>
	</HEAD>
    <BODY>
        <CENTER>
                <h1>Denon ARV-1803</h1><br>
                <div class="divTable">
                    <div class="divTableBody">
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">
                                <div class="myButton myButtonWakeUp" id="button_denon_wakeup">
                                    Wake-Up
                                </div>
                            </div>
                            <div class="divTableCell centerCell">
                                <div class="myButton myButtonStandby" id="button_denon_standby">
                                    Standby
                                </div>
                            </div>
                        </div>
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">
                                <div class="myButton" id="button_denon_VolumeUp">
                                    Volume Up
                                </div>
                            </div>
                            <div class="divTableCell centerCell">
                                <div class="myButton" id="button_denon_VolumeDown">
                                    Volume Down
                                </div>
                            </div>
                        </div>
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">Channels</div>
                            <div class="divTableCell centerCell">
                                <div class="myButton" id="button_denon_Mute">
                                    Mute
                                </div>
                            </div>
                        </div>
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">
                                <div class="myButton myButtonChannel" id="button_denon_phono">
                                    Phono
                                </div>
                            </div>
                            <div class="divTableCell centerCell">
                                <div class="myButton myButtonChannel" id="button_denon_dvdvdp">
                                    DVD/VDP<br><i>(Teufel)</i>
                                </div>
                            </div>
                        </div>
                        <!--
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">&nbsp;</div>
                            <div class="divTableCell centerCell">&nbsp;</div>
                        </div>
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">&nbsp;</div>
                            <div class="divTableCell centerCell">&nbsp;</div>
                        </div>
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">&nbsp;</div>
                            <div class="divTableCell centerCell">&nbsp;</div>
                        </div>
                        <div class="divTableRow">
                            <div class="divTableCell centerCell">&nbsp;</div>
                            <div class="divTableCell centerCell">&nbsp;</div>
                        </div>-->
                    </div>
                </div>
                <div class="centerCell">
                    <div class="myButton" id="button_record">
                        record
                    </div>
                </div>
                <div id="response"></div>
        </CENTER>
        <script type="text/javascript">
            document.getElementById('button_denon_wakeup')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/denon/wakeup", true);
                xhttp.send();
            });
            document.getElementById('button_denon_standby')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/denon/standby", true);
                xhttp.send();
            });
            document.getElementById('button_denon_VolumeUp')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/denon/volumeup", true);
                xhttp.send();
            });
            document.getElementById('button_denon_VolumeDown')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/denon/volumedown", true);
                xhttp.send();
            });
            document.getElementById('button_denon_Mute')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/denon/mute", true);
                xhttp.send();
            });
            document.getElementById('button_denon_phono')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/denon/channel/phono", true);
                xhttp.send();
            });
            document.getElementById('button_denon_dvdvdp')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/denon/channel/dvdvdp", true);
                xhttp.send();
            });
            document.getElementById('button_record')
              .addEventListener('click', function () {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("response").innerText =this.responseText;
                    }
                };
                xhttp.open("GET", "/record", true);
                xhttp.send();
            });
        </script>
    </BODY>
</HTML>
)=====";