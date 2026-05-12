-- Script de criação do banco de dados da Agenda
-- Executado automaticamente pelo app na primeira inicialização

CREATE TABLE IF NOT EXISTS tb_colaboradores (
    id                 INTEGER PRIMARY KEY AUTOINCREMENT,
    nome_colaborador   TEXT,
    username           TEXT NOT NULL UNIQUE,
    senha              TEXT NOT NULL,
    acesso_colaborador TEXT
);

-- Usuário padrão criado automaticamente se a tabela estiver vazia
-- Login: admin | Senha: 1234
INSERT INTO tb_colaboradores (nome_colaborador, username, senha)
VALUES ('Administrador', 'admin', '1234');
