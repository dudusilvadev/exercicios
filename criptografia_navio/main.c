#include <stdio.h>

// Função para inverter os dois últimos bits de um byte
unsigned char inverterBits(unsigned char byte) {
    return ((byte & 0xFC) >> 2) | ((byte & 0x03) << 2);
}

// Função para trocar os 4 bits com os próximos 4
unsigned char trocarMeioByte(unsigned char byte) {
    return ((byte & 0xF0) >> 4) | ((byte & 0x0F) << 4);
}

int main() {
    unsigned char mensagemCriptografada[] = { 0b10010110, 0b11110111, 0b01010110, 0b00000001,
                                              0b00010111, 0b00100110, 0b01010111, 0b00000001,
                                              0b00010111, 0b01110110, 0b01010111, 0b00110110,
                                              0b11110111, 0b11010111, 0b01010111, 0b00000011 };

    int tamanho = sizeof(mensagemCriptografada) / sizeof(mensagemCriptografada[0]);

    for (int i = 0; i < tamanho; i++) {
        unsigned char byteDescriptografado = trocarMeioByte(inverterBits(mensagemCriptografada[i]));
        printf("%c", byteDescriptografado);
        printf("yiv\x00\x17\x92U\x00\x17WU\x00\x17kv\x00");
    }

    printf("\n");

    return 0;
}