# Nutrifit
Proyectos de Programación final project.

Nutrifit es un programa que permite al usuario cumplir sus objetivos en cuanto deporte y dieta. Con Nutrifit, el usuario podrá generar distintos planes de ejercicio y dietas personalizadas a sus gustos y necesidades. Cada usuario tiene una cuenta y puede publicar recetas así como ver las publicadas por otros usuarios.

## Módulo Diet Planning
@author Esteban García Muñoz


Este módulo se encarga de generar una planificación de dieta personalizada para el usuario y guardarla en un archivo '.txt'. Para esto se tienen en cuenta varios factores como: el peso del usuario, la cantidad de deporte que hace o si quiere adelgazar o ganar peso. 

El usuario podrá elegir el número de días que dure la dieta. No hay límite de días, pero cuantos más se pidan, más tarda la el planning en generarse. 

El módulo cuenta con las siguientes clases:

**Food**:                Esta clase representa un alimento.
        
**FoodList**:            Esta clase representa un vector de alimentos. FoodList ha resultado ser un objeto muy versátil, siendo utilizado tanto para contener todos los                                alimentos disponibles como para manejar cómodamente pequeñas cantidades de alimentos.Se han implementado varios métodos para el fácil manejo                                  de esta clase. Por ejemplo, se ha sobrecargado el operador '[]', para poder hacer: 'FoodList[i]' y que se devuelva un alimento.
        
**Meal**:                Esta clase crea una comida que consta de tres alimentos diferentes. Se tienen en cuenta las distintas categorías que puede ser un alimento                                    para crear desayuno, comida y cena con los alimentos que corresponden más a cada hora del día. Genera la Meals cuadrando los alimentos                                        necesarios para que sumen un número concreto de Kilocalorías en total.La función 'writeMeal(&ofstream file)' usa una referencia a un archivo                                  abierto por otra función de otra clase. También se ha hecho sobrecarga de operadores para poder acceder a los alimentos de un Meal. 'Meal[i]'                                 devolverá el primer, segundo o tercer alimento de la comida. Los corchetes no admitirán ningún número menor que uno o mayor que tres.
                               
**Day**:                 Esta representa un día completo con número y con 3 Meals: desayuno, comida y cena. Se usará sobre todo para generar la dieta y escribirla en                                  el archivo '.txt'.

**Diet**:                Utilizando las clases Meal y Day. Genera el planning de la dieta con la duración (en días) que haya querido el usuario y  la escribe en un                                    archivo '.txt'.

**UserStatus**:          Maneja información concreta del usuario para calcular las Kilocalorías que va a necesitar consumir cada día del planning.

