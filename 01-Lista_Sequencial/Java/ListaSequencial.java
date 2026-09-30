/**
 * Implementação genérica da Lista Sequencial em Java.
 * Equivalente direta da versão em C.
 * 
 * @author Guilherme Parnaíba Nunes
 */
public class ListaSequencial<T> {
    private static final int MAX = 100;
    private T[] itens;
    private int tamanhoAtual;

    @SuppressWarnings("unchecked")
    public ListaSequencial() {
        // Em Java, não instanciamos arrays genéricos diretamente (new T[MAX]).
        // Criamos um array de Object e fazemos o cast.
        this.itens = (T[]) new Object[MAX];
        this.tamanhoAtual = 0;
    }

    public boolean listaCheia() {
        return this.tamanhoAtual == MAX;
    }

    public boolean listaVazia() {
        return this.tamanhoAtual == 0;
    }

    public boolean inserir(T item, int posicao) {
        if (listaCheia() || posicao < 0 || posicao > tamanhoAtual) {
            return false;
        }

        // Shift para a direita: abre espaço
        for (int i = tamanhoAtual; i > posicao; i--) {
            itens[i] = itens[i - 1];
        }

        itens[posicao] = item;
        tamanhoAtual++;
        return true;
    }

    // No Java, retornamos o objeto removido ou null se der erro.
    public T remover(int posicao) {
        if (listaVazia() || posicao < 0 || posicao >= tamanhoAtual) {
            return null; 
        }
        
        T itemRemovido = itens[posicao];

        // Shift para a esquerda: tampa o buraco
        for (int i = posicao; i < tamanhoAtual - 1; i++) {
            itens[i] = itens[i + 1];
        }

        // Limpa a última referência para ajudar o Garbage Collector
        itens[tamanhoAtual - 1] = null;
        tamanhoAtual--;

        return itemRemovido;
    }

    public int buscar(T item) {
        for (int i = 0; i < tamanhoAtual; i++) {
            // Em Java, objetos são comparados via .equals(), equivalente a nossa macro ITEM_EQUALS do C
            if (item.equals(itens[i])) { 
                return i;
            }
        }
        return -1; // Não encontrado
    }

    public void imprimirLista() {
        System.out.print("Lista [ ");
        for (int i = 0; i < tamanhoAtual; i++) {
            // O print em Java chama o .toString() do objeto automaticamente
            System.out.print(itens[i]); 
            if (i < tamanhoAtual - 1) System.out.print(", ");
        }
        System.out.println(" ] Tamanho: " + tamanhoAtual + "/" + MAX);
    }

    // Getters auxiliares para a aplicação prática
    public int getTamanhoAtual() { return tamanhoAtual; }
    public int getCapacidadeMaxima() { return MAX; }
    public T getItem(int i) { return itens[i]; }
}