/**
 * AULA IoT - Embarcatech - Ricardo Prates - 003 - Conectar a uma rede local - wlan
 *
 * Material de suporte
 * 
 * https://www.raspberrypi.com/documentation/pico-sdk/networking.html#group_pico_cyw43_arch_1ga33cca1c95fc0d7512e7fef4a59fd7475 
 */

#include <stdio.h>                  // Biblioteca padrão para entrada e saída
#include "pico/stdlib.h"            // Biblioteca da Raspberry Pi Pico para funções padrão (GPIO, temporização, etc.)

#include "pico/cyw43_arch.h"        // Biblioteca para arquitetura Wi-Fi da Pico com CYW43
#include "lwipopts.h"               // Lightweight IP stack - O lwIP é uma implementação independente do conjunto de protocolos TCP/IP              

// Credenciais WIFI - Tome cuidado se publicar no github!
const char WIFI_SSID[] = "SEU_SSID";
const char WIFI_PASSWORD[] = "SUA_SENHA";

 int main(){

    //Inicializa todos os tipos de bibliotecas stdio padrão presentes que estão ligados ao binário.
    stdio_init_all();

    //Inicializa a arquitetura do cyw43
    if (cyw43_arch_init()) {
        printf("Falha para iniciar o cyw43\n");
        return - 1;
    }
    printf("cyw43 conectado\n");

    // Ativa o Wi-Fi no modo Station, de modo a que possam ser feitas ligações a outros pontos de acesso Wi-Fi.
    cyw43_arch_enable_sta_mode();

    // Conectar à rede WiFI - fazer um loop até que esteja conectado
    while(cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000) != 0){
        printf("Tentando conexão...\n");
    }
    printf("Conectado com sucesso! \n");

    // Caso seja a interface de rede padrão.
    if (netif_default)
    {
        printf("IP do dispositivo: %s\n", ipaddr_ntoa(&netif_default->ip_addr));
    }
    
    return 0;
 }