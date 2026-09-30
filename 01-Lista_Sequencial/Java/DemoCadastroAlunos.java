public class DemoCadastroAlunos {
    
    public static void relatorioTurma(ListaSequencial<Aluno> l) {
        System.out.printf("\n--- DIARIO DE CLASSE (%d/%d alunos) ---\n", l.getTamanhoAtual(), l.getCapacidadeMaxima());
        for (int i = 0; i < l.getTamanhoAtual(); i++) {
            Aluno a = l.getItem(i);
            System.out.printf("[%d] Matricula: %d | Nome: %s\n", i, a.getMatricula(), a.getNome());
        }
        System.out.println("--------------------------------------");
    }

    public static void main(String[] args) {
        // Instancia a lista definindo o tipo T como Aluno
        ListaSequencial<Aluno> turma = new ListaSequencial<>();

        Aluno a1 = new Aluno(202601, "Guilherme Parnaiba");
        Aluno a2 = new Aluno(202602, "Ada Lovelace");
        Aluno a3 = new Aluno(202603, "Alan Turing");

        turma.inserir(a1, 0);
        turma.inserir(a2, 1);
        turma.inserir(a3, 1); // Shift na Ada

        relatorioTurma(turma);

        Aluno removido = turma.remover(1);
        if (removido != null) {
            System.out.printf("\nAluno transferido: %s (Mat: %d)\n",
                    removido.getNome(), removido.getMatricula());
        }

        relatorioTurma(turma);
    }
}