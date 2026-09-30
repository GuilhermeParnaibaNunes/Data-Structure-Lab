public class DemoListaSequencial {
    public static void main(String[] args) {
        // Instancia a lista definindo o tipo T como Integer
        ListaSequencial<Integer> minhaLista = new ListaSequencial<>();

        System.out.printf("\n--- Iniciando testes da Lista Sequencial ---\n");

        minhaLista.inserir(10, 0);
        minhaLista.inserir(30, 1);
        minhaLista.inserir(20, 1); // Forçando shift

        minhaLista.imprimirLista();

        int pos = minhaLista.buscar(20);
        if (pos != -1) {
            System.out.println("\nItem 20 encontrado no indice: " + pos);
        }

        System.out.println("\nRemovendo o item do indice 0...");
        Integer removido = minhaLista.remover(0);
        if (removido != null) {
            System.out.println("Item removido com sucesso: " + removido);
        }

        minhaLista.imprimirLista();
    }
}