#include "Jogo.h"

Jogo::Jogo():   
    
    pJogador2(nullptr),
    LEs(nullptr),
    fase(nullptr),
    //gerenciadorColisoes(),
    relogio()

{
    gerenciadorColisoes = gerenciadorColisoes->getInstancia();
    gerenciadorEventos = gerenciadorEventos->getInstancia();
    gerenciadorGrafico = gerenciadorGrafico->getInstancia();
    gerenciadorTiles = gerenciadorTiles->getInstancia();

    Ente::setGGrafico(gerenciadorGrafico);
    Menu::setGEventos(gerenciadorEventos);
    Fase::setGTiles(gerenciadorTiles);

    ranking = new MenuRanking();

    
    //Seta os gerenciadores
    gerenciadorEventos->setGGraf(gerenciadorGrafico);
    gerenciadorTiles->setGColisoes(gerenciadorColisoes);
    gerenciadorTiles->setGGraf(gerenciadorGrafico);

    menu = new MenuPrincipal();
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
    
    //La?o de execu??o do jogo
    while(gerenciadorGrafico->janelaAberta())
    {

        verificaPause();
   
        verificaFase();

        verificaAtualizacoes();

        //Limpa a tela
        gerenciadorGrafico->limpar(105, 105, 105); //Limpa tela na cor cinza

        gerenciaColisoes();

        //Desenha na tela o mapa de cada fase: (BackGround, tiles...)
        fase->desenhar();

        desenhaEntidades();

        //Display ma tela de tudo de foi setado nela
        gerenciadorGrafico->mostrar();
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

            menu = new MenuJogadores();
            indiceMenu = menu->executar();
            trocarMenu();
        }
        else if (indiceMenu == 1) { //Fases

            menu = new MenuFases();
            indiceMenu = menu->executar();
            trocarMenu();
        }
        else if (indiceMenu == 2) { //Ranking
            
            ranking->executar(); //Mostra o ranking
            menu = new MenuPrincipal();
            indiceMenu = menu->executar();
            trocarMenu();
        }
        else {
            gerenciadorGrafico->getJanela()->close();
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
        gerenciadorTiles->limpaTiles();
        gerenciadorColisoes->limparTiles();
        
        if (numFase == 0 || numFase == 1) {
           
            pontuacao = 0;

            pJogador1->resetaVida();
            if (pJogador2) {
                pJogador2->resetaVida();
            }

            fase = new FaseGrama(pJogador1, pJogador2, "images/tilesGrama.png", "faseGrama.txt", "images/fundoGrama.png");
            LEs = fase->getListaEntidades();
            
        }
        else if (numFase == 2) {
         
            fase = new FaseCaverna(pJogador1, pJogador2, "images/tilesCaverna.png","faseCaverna.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
            
        }
        else {
           
            fase = new FaseCavernaChefao(pJogador1, pJogador2, "images/tilesCaverna.png", "faseCavernaChefao.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
           
        }

        gerenciadorColisoes->setListaEntidades(LEs);
        executarJogo();

    }
    else if (indiceMenu == 1) { //2 jogadores
        
        pJogador2 = new CuboExplorador(Vector2f(0, 0), Vector2f(0, 0), "images/explorador.png");
        pJogador2->setGEventos(gerenciadorEventos);
        
        delete fase;
        
        gerenciadorTiles->limpaTiles();
        gerenciadorColisoes->limparTiles();
        
        if (numFase == 0 || numFase == 1) {
            
            pontuacao = 0;

            fase = new FaseGrama(pJogador1, pJogador2, "images/tilesGrama.png", "faseGrama.txt", "images/fundoGrama.png");
            LEs = fase->getListaEntidades();
            
        }
        else if (numFase == 2) {
            
            
            fase = new FaseCaverna(pJogador1, pJogador2, "images/tilesCaverna.png", "faseCaverna.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
            
        }
        else {
            
            fase = new FaseCavernaChefao(pJogador1, pJogador2, "images/tilesCaverna.png", "faseCavernaChefao.txt", "images/fundoCaverna.png");
            LEs = fase->getListaEntidades();
            
        }

        gerenciadorColisoes->setListaEntidades(LEs);
        executarJogo();

    }
    else if (indiceMenu == 2) { //Voltar
        delete menu;
        
       
        menu = new MenuPrincipal();
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

            menu = new MenuPrincipal();
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
    
    
    pontuacao = 0;

    pJogador1->resetaVida();

    if (pJogador2) {
        pJogador2->resetaVida();
    }
    
    if (indiceMenu == 0) {              //Fase Grama

        menu = new MenuJogadores();

        indiceMenu = menu->executar();
        trocarMenu(true,1);

    }
    else if (indiceMenu == 1) {         //Fase Caverna
        
        menu = new MenuJogadores();
        
        indiceMenu = menu->executar();
        trocarMenu(true,2);
    }   
    else if (indiceMenu == 2) {         //Fase Caverna Chefao
         
        menu = new MenuJogadores();
        
        indiceMenu = menu->executar();
        trocarMenu(true, 3);
    }
    else if (indiceMenu == 3) {         //Voltar
        
        menu = new MenuPrincipal();
        
        indiceMenu = menu->executar();
        trocarMenu();
    }
}

void Jogo::verificaPause()
{

    int evento = gerenciadorEventos->verificaEvento();

    if (evento == 1) {       //Esc durante o jogo (pause)
        relogio.pausar();
        delete menu;
        menu = new MenuPause();
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
        
        pontuacao = pontuacao + 200;
    
    }

}

void Jogo::verificaAtualizacoes()
{
    //Atualiza as posi??es de cada entidade conforme o relogio "passa"
    double t = relogio.getTempo();

    //Verifica se o jogador foi morto
    if (pJogador1->getDestruir()) {

        pJogador1->setDestruir(false);

        reiniciaFase();

    }

    if (pJogador2 && pJogador2->getDestruir()) {

        pJogador2->setDestruir(false);

        reiniciaFase();
       
    }

    fase->criarProjeteis();
    LEs = fase->getListaEntidades();

    //Atualiza todas as entidades da fase em execu??o
    //for (int i = 0; i < LEs->getLista().getTam(); i++)
    for (int i = 0; (*LEs) > i; i++) {
        Entidade* pAux = NULL;

        pAux = (*LEs)[i];
        //pAux = LEs->getLista().getItem(i);

        pAux->mover(t);

        pAux->atualizar((float)t);

        pontuacao = pontuacao + pAux->getPontos();

        if (pAux->getDestruir()) {

            LEs->getLista().pop(pAux);

        }

    }
}

void Jogo::gerarFase()
{
   
    gerenciadorTiles->limpaTiles();
    gerenciadorColisoes->limparTiles();
    
    //Passa da fase grama para fase Caverna
    if (fase->getFaseAtual() == 1) {
     
        delete fase;
        
        fase = new FaseCaverna(pJogador1, pJogador2, "images/tilesCaverna.png", "faseCaverna.txt", "images/fundoCaverna.png");
        LEs = fase->getListaEntidades();
     
    }
    //Passa de fase Caverna para a Caverna Chefao
    else if (fase->getFaseAtual() == 2) {
        delete fase;
        
        fase = new FaseCavernaChefao(pJogador1, pJogador2, "images/tilesCaverna.png", "faseCavernaChefao.txt", "images/fundoCaverna.png");
        LEs = fase->getListaEntidades();
        
    }
    else {
        
        ranking->cadastrar(cadastrarJogadas.executar((int)pontuacao), (int)pontuacao); //Cadastra pontuacao e a coloca no ranking
        ranking->executar(); //Mostra o ranking
        
        menu = new MenuPrincipal();
        
        indiceMenu = menu->executar();
        trocarMenu();
    }

    gerenciadorColisoes->setListaEntidades(LEs);

}

void Jogo::gerenciaColisoes()
{
    
    gerenciadorColisoes->VerificaColisoes(pJogador1);

    if (pJogador2) {
        gerenciadorColisoes->VerificaColisoes(pJogador2);
    }

}

void Jogo::desenhaEntidades()
{
    
    
    gerenciadorGrafico->desenhaPontos(pontuacao);
    
   
    
    
    for (int i = 0; i < LEs->getLista().getTam(); i++)
    {
        Entidade* pAux = NULL;
        
        ListaEntidades& lAux = *LEs;
        //Aponta para a elemento<entidades> na posi??o i
        pAux = lAux[i];

        (*pAux).desenhar();
        pAux->desenharVidas();
    }
}

void Jogo::reiniciaFase()
{
    gerenciadorTiles->limpaTiles();
    gerenciadorColisoes->limparTiles();

 
        
       pJogador1->resetaVida();
       if (pJogador2) {
           pJogador2->resetaVida();
       }

       pontuacao -= 450;
    
    
    
    //Passa da fase grama para fase Caverna
    if (fase->getFaseAtual() == 1) {

        delete fase;
        fase = new FaseGrama(pJogador1, pJogador2, "images/tilesGrama.png", "faseGrama.txt", "images/fundoGrama.png");
        LEs = fase->getListaEntidades();
    }
    //Passa de fase Caverna para a Caverna Chefao
    else if (fase->getFaseAtual() == 2) {
        
        delete fase;
        fase = new FaseCaverna(pJogador1, pJogador2, "images/tilesCaverna.png", "faseCaverna.txt", "images/fundoCaverna.png");
        LEs = fase->getListaEntidades();
    }
    else {
        
        delete fase;
        fase = new FaseCavernaChefao(pJogador1, pJogador2, "images/tilesCaverna.png", "faseCavernaChefao.txt", "images/fundoCaverna.png");
        LEs = fase->getListaEntidades();

    }
    gerenciadorColisoes->setListaEntidades(LEs);
}
