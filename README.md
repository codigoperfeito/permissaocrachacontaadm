# **Sistema de Controle de Acesso com Crachás RFID - Permissão Crachá Conta Adm**

Este projeto visa implementar um sistema de controle de acesso utilizando crachás RFID, Arduino Uno e display OLED I2C. A solução foi desenvolvida para automatizar o processo de liberação de acesso, proporcionando maior eficiência e organização. O código e os testes foram realizados com o objetivo de integrar a tecnologia na rotina da empresa, permitindo que os funcionários utilizem seus crachás de identificação para acessar áreas restritas.

---

## **Recursos Utilizados**

- **Hardware:**
  - Arduino Uno
  - Display OLED I2C
  - Leitor RFID
  - Crachás RFID
- **Software:**
  - IDE do Arduino
  - Bibliotecas RFID e OLED

---

## **Objetivo do Projeto**

Implementar um sistema de controle de acesso para a empresa **Conta Adm Administradora de Bens Ltda.**, onde os funcionários possam utilizar seus crachás RFID para ter acesso a áreas restritas, como por exemplo, a catraca da empresa.

O sistema foi desenvolvido para:
- Ler o ID de um crachá RFID.
- Exibir a mensagem "Acesso Liberado" ou "Acesso Negado" no display OLED.
- Garantir um processo de liberação de acesso automatizado e eficiente.

---

## **Como Funciona**

1. **Leitura do Crachá RFID**: O sistema utiliza um leitor RFID para capturar o ID de um crachá.
2. **Verificação do ID**: O ID lido é comparado com uma lista pré-programada de IDs autorizados.
3. **Exibição de Resultado**: O display OLED exibe uma mensagem de "Acesso Liberado" ou "Acesso Negado", conforme o ID.

---

## **Como Usar**

1. Conecte o Arduino Uno à sua máquina.
2. Instale as bibliotecas necessárias através da IDE do Arduino:
   - `Adafruit_SSD1306` para o display OLED.
   - `MFRC522` para o leitor RFID.
3. Faça o upload do código para o Arduino.
4. Conecte o hardware (leitor RFID e display OLED).
5. Passe o crachá RFID pela leitora e observe a resposta no display.

---

O código fonte está disponível no repositório, dentro do arquivo `permissao_cracha.ino`.


---

## **Licença**

Este projeto é de código aberto e está disponível para uso e modificação conforme a licença [MIT](https://opensource.org/licenses/MIT).

---

## **Código**

O código utilizado neste projeto está no arquivo `permissao_cracha.ino`, que pode ser encontrado no repositório do GitHub. Certifique-se de seguir as instruções de como carregar o código na IDE do Arduino para uma execução bem-sucedida.

---

Este README foi estruturado para fornecer uma descrição clara do projeto, seus objetivos, como usar o código, e as evidências coletadas durante a atividade. Além disso, oferece um link direto para o código no GitHub e fornece as instruções necessárias para replicar o sistema.
