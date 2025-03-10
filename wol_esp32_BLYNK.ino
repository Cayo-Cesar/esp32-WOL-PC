#define BLYNK_TEMPLATE_ID "****"
#define BLYNK_TEMPLATE_NAME "****"
#define BLYNK_AUTH_TOKEN "****"  // Token do Blynk

#include <WiFi.h>
#include <WiFiUdp.h>
#include <BlynkSimpleEsp32.h>

const char* ssid = "****";       
const char* password = "****"; 

const char* broadcastIP = "255.255.255.255"; 
const int udpPort = 9;  // Porta padrão do Wake-on-LAN

const uint8_t macAddress[] = {0x00, 0xE0, 0x4F, 0x15, 0x5C, 0x64};  

WiFiUDP udp;  

// Função para enviar o Magic Packet
void sendMagicPacket() {
    uint8_t magicPacket[102];  // Magic Packet tem 102 bytes
    memset(magicPacket, 0xFF, 6);  

    for (int i = 1; i <= 16; i++) {  
        memcpy(magicPacket + (i * 6), macAddress, 6);
    }

    udp.beginPacket(broadcastIP, udpPort);
    udp.write(magicPacket, sizeof(magicPacket));
    udp.endPacket();

    Serial.println("Magic Packet enviado!");
}

BLYNK_WRITE(V0) {
    int buttonState = param.asInt(); 
    if (buttonState == 1) { 
        Serial.println("Botão no Blynk pressionado! Enviando Magic Packet...");
        sendMagicPacket();
    }
}

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    Serial.print("Conectando ao Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi conectado!");

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
    Blynk.run(); 
}
