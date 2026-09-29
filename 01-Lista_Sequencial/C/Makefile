# Compilador e Flags
CC = gcc

# AddressSanitizer não é confiável em todos os toolchains MinGW/MSYS2
# (ambiente UCRT64 costuma não ter libasan disponível). Habilitamos
# apenas fora do Windows; veja o README para instruções de build
# completo (com ASan) via WSL2.
ifeq ($(OS),Windows_NT)
    SANITIZE_FLAGS =
else
    SANITIZE_FLAGS = -fsanitize=address
endif

CFLAGS = -Wall -Wextra -g $(SANITIZE_FLAGS)

# Diretórios e Nomes
BIN_DIR = bin
TARGET_GENERIC = $(BIN_DIR)/demo_lista_sequencial
TARGET_APP = $(BIN_DIR)/demo_cadastro_alunos

.PHONY: all clean

# Regra principal
all: $(TARGET_GENERIC) $(TARGET_APP)

# Garante que a pasta bin/ exista
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compila o teste técnico genérico
$(TARGET_GENERIC): $(BIN_DIR) lista_sequencial.o demo_lista_sequencial.o
	$(CC) $(CFLAGS) lista_sequencial.o demo_lista_sequencial.o -o $(TARGET_GENERIC)

# Compila a aplicação prática (CRUD)
# demo_cadastro_alunos.c injeta seu próprio TipoItem e inclui
# lista_sequencial.c diretamente (Unity Build) — por isso depende
# também da fonte/header genéricos, não só do próprio arquivo.
$(TARGET_APP): $(BIN_DIR) demo_cadastro_alunos.c lista_sequencial.c lista_sequencial.h
	$(CC) $(CFLAGS) demo_cadastro_alunos.c -o $(TARGET_APP)

# Objetos genéricos
lista_sequencial.o: lista_sequencial.c lista_sequencial.h
	$(CC) $(CFLAGS) -c lista_sequencial.c

demo_lista_sequencial.o: demo_lista_sequencial.c lista_sequencial.h
	$(CC) $(CFLAGS) -c demo_lista_sequencial.c

# Limpeza
clean:
	rm -rf $(BIN_DIR) *.o