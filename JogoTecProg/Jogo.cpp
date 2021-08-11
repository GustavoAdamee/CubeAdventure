#include "Jogo.h"

Jogo::Jogo():   
    
    pJogador2(nullptr),
    LEs(nullptr),
    fase(nullptr),
    gerenciadorColisoes(),
    relogio()

{
    Ente::setGGrafico(&gerenciadorGrafico);
    gerenciadorEventos.setGGraf(gerenciadorGrafico);
    gerenciadorTiles.setGColisoes(&gerenciadorColisoes);
    gerenciadorTiles.setGGraf(&gerenciadorGrafico);

    menu = new MenuPrincipal(gerenciadorEventos);
    indiceMenu = menu->executar();
    
    pJogador1 = new CuboCowboy(Vector2f(0, 0), Vector2f(0, 0), "images/cowboy.png");
    pJogador1->setGEventos(gerenciadorEventos);

    trocarMenu();
}

Jogo::~Jogo()
{
    pJogador1 = nullptr;
    pJogador2 = nullptr;

    LEs = nullptr;

    fase = nullptr;

    menu = nullptr;

    Ente::setGGrafico(nullptr);
}

void Jogo::executarJogo()
{
    
    relogio.reiniciar();
    
    //Laço de execução do jogo
    while(gerenciadorGrafico.janelaAberta())
    {

        verificaPause();
   
        verificaFase();

        verificaAtualizacoes();

        //Limpa a tela
        gerenciadorGrafico.limpar(105, 105, 105); //Limpa tela na cor cinza

        gerenciaColisoes();

        //Desenha na tela o mapa de cada fase: (BackGround, tiles...)
        fase->desenhar();

        desenhaEntidades();

        //Display ma tela de tudo de foi setado nela
        gerenciadorGrafico.mostrar();
    }
}

void Jogo::trocarMenu(bool Fases, int indicaFase)
{
    if (menu->getTipo() == 1) {
        gerenciarMenuPrincipal();
    }
    else if (menu->getTipo() == 2 && Fases == true) {
        gerenciarMenuJogadores(indicaFase);
    }
    else if (menu->getTipo() == 2) {
        gerenciarMenuJogadores();
    }
    else if (menu->getTipo() == 3) {
        gerenciarMenuPause();
    }
    else if (menu->getTipo() == 4) {
        gerenciarMenuFases();
    }
}

void Jogo::gerenciarMenuPrincipal()
{
    
    if (menu->getTipo() == 1 && indiceMenu == 3) { //Sair

    }
    else {
        delete menu;

        if (indiceMenu == 0) { //Jogar

            menu = new MenuJogadores(gerenciadorEventos);
            indiceMenu = menu->executar();
            trocarMenu();
        }
        else if (indiceMenu == 1) { //Fases

            menu = new MenuFases(gerenciadorEventos);
            indiceMenu = menu->executar();
            trocarMenu();
        }
    }
    
}

void Jogo::gerenciarMenuJogadores(int numFase)
{
    
    if (indiceMenu == 0) {  //1 Jogador
        
        if (pJogador2) {
            pJogador2 = nullptr;
        }
        
        
        delete fase;
        gerenciadorTiles.limpaTiles();
        gerenciadorColisoes.limparTiles();
        
        if (numFase == 0 || numFase == 1) {
           
            fase = new FaseGrama(pJogador1, pJogador2, gerenciadorTiles, "images/tilesGrama.png", "faseGrama.txt", "images/fundoGrama.png");
            LEs = fase->getListaEntidades();
            
        }
        else if (numFase == 2) {
         
            fase = new FaseCaverna(pJogador1, pJogador2, gerenciadorTiles, "images/tilesCaverna.png","faseCaverna.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
            
        }
        else {
           
            fase = new FaseCavernaChefao(pJogador1, pJogador2, gerenciadorTiles, "images/tilesCaverna.png", "faseCavernaChefao.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
           
        }

        gerenciadorColisoes.setListaEntidades(LEs);
        executarJogo();

    }
    else if (indiceMenu == 1) { //2 jogadores
        
        pJogador2 = new CuboExplorador(Vector2f(0, 0), Vector2f(0, 0), "images/explorador.png");
        pJogador2->setGEventos(gerenciadorEventos);
        
        delete fase;
        
        gerenciadorTiles.limpaTiles();
        gerenciadorColisoes.limparTiles();
        
        if (numFase == 0 || numFase == 1) {
            
            fase = new FaseGrama(pJogador1, pJogador2, gerenciadorTiles, "images/tilesGrama.png", "faseGrama.txt", "images/fundoGrama.png");
            LEs = fase->getListaEntidades();
            
        }
        else if (numFase == 2) {
            
            fase = new FaseCaverna(pJogador1, pJogador2, gerenciadorTiles, "images/tilesCaverna.png", "faseCaverna.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
            
        }
        else {
            
            fase = new FaseCavernaChefao(pJogador1, pJogador2, gerenciadorTiles, "images/tilesCaverna.png", "faseCavernaChefao.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
            
        }

        gerenciadorColisoes.setListaEntidades(LEs);
        executarJogo();

    }
    else if (indiceMenu == 2) { //Voltar
        delete menu;
       
        menu = new MenuPrincipal(gerenciadorEventos);
        indiceMenu = menu->executar();
        
        trocarMenu();
    }
}

void Jogo::gerenciarMenuPause()
{
 
    if (indiceMenu == 0) {      //Continuar

    }
    else {
        
        delete menu;
        
        if (indiceMenu == 1) { //Menu principal

            menu = new MenuPrincipal(gerenciadorEventos);
            indiceMenu = menu->executar();
            trocarMenu();
        }

        else if (indiceMenu == 2) { //Sair do jogo

        }
    }
}

void Jogo::gerenciarMenuFases()
{
    
    delete menu;
    
    menu = new MenuJogadores(gerenciadorEventos);
    
    if (indiceMenu == 0) {              //Fase Grama
        
        indiceMenu = menu->executar();
        trocarMenu(true,1);
    }
    else if (indiceMenu == 1) {         //Fase Caverna
        
        indiceMenu = menu->executar();
        trocarMenu(true,2);
    }   
    else if (indiceMenu == 2) {         //Fase Caverna Chefao
        
        indiceMenu = menu->executar();
        trocarMenu(true, 3);
    }
    else if (indiceMenu == 3) {         //Voltar
        
        indiceMenu = menu->executar();
        trocarMenu();
    }
}

void Jogo::verificaPause()
{

    int evento = gerenciadorEventos.verificaEvento();

    if (evento == 1) {       //Esc durante o jogo (pause)
        relogio.pausar();
        delete menu;
        menu = new MenuPause(gerenciadorEventos);
        indiceMenu = menu->executar();
        trocarMenu();
        relogio.reiniciar();
    }

}

void Jogo::verificaFase()
{

    fase->verificaFase();
    if (fase->passouFase()) {
        gerarFase();
    }

}

void Jogo::verificaAtualizacoes()
{
    //Atualiza as posições de cada entidade conforme o relogio "passa"
    double t = relogio.getTempo();
    //Move os jogadores 
    pJogador1->mover(t);
    if (pJogador2 != nullptr) {
        pJogador2->mover(t);
    }
 
    for (int i = 0; i < LEs->getLista().getTam(); i++) {
        Entidade* pAux = NULL;
        pAux = LEs->getLista().getItem(i);
        pAux->atualizar(t);
    }

}

void Jogo::gerarFase()
{
   
    gerenciadorTiles.limpaTiles();
    gerenciadorColisoes.limparTiles();
    
    //Passa da fase grama para fase Caverna
    if (fase->getFaseAtual() == 1) {
        delete fase;
        
        fase = new FaseCaverna(pJogador1, pJogador2, gerenciadorTiles, "images/tilesCaverna.png", "faseCaverna.txt", "images/fundoCaverna.png");
        LEs = fase->getListaEntidades();
       
    }
    //Passa de fase Caverna para a Caverna Chefao
    else if (fase->getFaseAtual() == 2) {
        delete fase;
        
        fase = new FaseCavernaChefao(pJogador1, pJogador2, gerenciadorTiles, "images/tilesCaverna.png", "faseCavernaChefao.txt", "images/fundoCaverna.png");
        LEs = fase->getListaEntidades();
        
    }

    gerenciadorColisoes.setListaEntidades(LEs);
}

void Jogo::gerenciaColisoes()
{
    
    gerenciadorColisoes.VerificaColisoes(pJogador1);

    if (pJogador2) {
        gerenciadorColisoes.VerificaColisoes(pJogador2);
    }
}

void Jogo::desenhaEntidades()
{
    for (int i = 0; i < LEs->getLista().getTam(); i++)
    {
        Entidade* pAux = NULL;
        pAux = LEs->getLista().getItem(i); //Aponta para a elemento<entidades> na posição i
        pAux->desenhar();
    }
}
