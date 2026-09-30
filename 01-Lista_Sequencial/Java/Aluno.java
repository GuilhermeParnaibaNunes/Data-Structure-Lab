public class Aluno {
    private int matricula;
    private String nome;

    public Aluno(int matricula, String nome) {
        this.matricula = matricula;
        this.nome = nome;
    }

    // Define a regra de busca: alunos são iguais se a matrícula for igual
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Aluno aluno = (Aluno) obj;
        return matricula == aluno.matricula;
    }

    // Garante hashcode consistente com equals, baseado na matrícula
    @Override
    public int hashCode() {
        return Integer.hashCode(matricula);
    }

    // Define como o aluno aparece quando a lista tenta imprimi-lo
    @Override
    public String toString() {
        return "{Mat: " + matricula + ", Nome: " + nome + "}";
    }

    public int getMatricula() { return matricula; }
    public String getNome() { return nome; }
}