#include <WiFi.h>
#include <WiFiUdp.h>

// Configuração da rede Wi-Fi
const char* ssid = "****";      
const char* password = "********"; 

const char* broadcastIP = "255.255.255.255"; 
const int udpPort = 9;  

const uint8_t macAddress[] = {0x00, 0xE0, 0x4F, 0x15, 0x5C, 0x64};  

#define BUTTON_PIN 0  

WiFiUDP udp;  // Criar instância UDP

// Função para enviar o Magic Packet
void sendMagicPacket() {
    uint8_t magicPacket[102];  

    memset(magicPacket, 0xFF, 6);

    for (int i = 1; i <= 16; i++) {  
        memcpy(magicPacket + (i * 6), macAddress, 6);
    }

    udp.beginPacket(broadcastIP, udpPort);
    udp.write(magicPacket, sizeof(magicPacket));
    udp.endPacket();

    Serial.println("Magic Packet enviado!");
}

void setup() {
    Serial.begin(115200); 
    WiFi.begin(ssid, password);  // Conectar ao Wi-Fi

    Serial.print("Conectando ao Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {  
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi conectado!");

    pinMode(BUTTON_PIN, INPUT_PULLUP);  
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {  
        Serial.println("Botão pressionado! Enviando Magic Packet...");
        sendMagicPacket();
        delay(1000); 
    }
}
