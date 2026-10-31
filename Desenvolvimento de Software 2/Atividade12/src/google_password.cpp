#include "google_password.hpp"

#include <iostream>
#include <set>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {

  // TODO: Implemente este metodo

  if(checkPassword(password)){
    Usuario usuario = Usuario (login, password);
    m_passwords.insert({url,usuario});
  }

  
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
}

void GooglePassword::remove(const std::string& url) {
  for (auto it = m_passwords.begin(); it!=m_passwords.end(); it++){
    if(it->first.compare(url) == 0){
      m_passwords.erase(it);
      break;
    }
  }
  // TODO: Implemente este metodo
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo

  for (auto it = m_passwords.begin(); it!=m_passwords.end(); it++){
    if(it->first.compare(url) == 0){
      if(it->second.getPassword().compare(old_password) == 0){
        if(checkPassword(new_password)){
          it->second.setPassword(new_password);
          it->second.setLogin(login);
        }
      }
      break;
    }
  } 
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
  std::cout << m_passwords.size() << std::endl;
  std::set <std::string> urls;
  for (auto it = m_passwords.begin(); it!=m_passwords.end(); it++){
    urls.insert(it->first);
  }

  for(std::string url: urls){
    std::cout << url << ": " << m_passwords.at(url).getLogin() << " and " << m_passwords.at(url).getPassword() << std::endl;
  }
}

bool GooglePassword::checkPassword(const std::string& password) const {
  // TODO: Implemente este metodo

  if(password.size() <= 50){
    if (password.size() >= 6){
     if ((password.find("123456"))==std::string::npos){
      if ((password.find(" "))==std::string::npos){
        return true;
      }
     }
    }
  }
  return false;
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
}

