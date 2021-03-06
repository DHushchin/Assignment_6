# Assignment #6. Trees
В цій лабораторній роботі ви маєте працювати в бригадах по 3 людини. Лабораторна робота, що була написана без використання git, не приймається. Один комміт "lab is done" не вважається використанням git. Враховуючи розмір та складність завдання, очевидно, що кожен учасник бригади має зробити щонайменше кілька комітів у репозиторій.

## Загальне завдання
* Розібратись в загальному і структурою даних "дерево" — де використовується, чому так називається.
* Розібрати всі запропоновані варіанти - виконувати потрібно тільки одне (за варіантом), але теоретичні питання будуть стосуватись всіх завданнь.
* Уважно розібратись з алгоритмічної складністю роботи з деревами (а точніше — звідки там так часто береться логарифм)
* Перегляньте запис лекції з детальним описом задачі і методів її вирішення (посилання на лекцію є в чаті)

## Варіант #0. Рендеринг зображення метод трасування променів
Написати програму, що приймає на вхід файл формату wavefront obj, а на виході створює зображення формату bmp або будь-якого іншого поширеного формату з візуалізацією моделі, яка знаходиться у вхідному файлі.

*В цьому варіанті дозволяється використовувти 3rd party бібліотеки для читання файлів \*.obj та для запису файлів із зображенням. Вочевидь, для запису зображення ви можете скористатися кодом, що написали самі або ваші одногрупники в попередній лабораторній роботі.*

### Опис методу трасування променів
Метод трасування променів полягає в наступному. Геометрія, яку треба візуалізувати, задається у вигляді набору трикутників у 3d просторі. Камера, що "знімає" сцену, задається точкою в просторі та вектором напряму зйомки. Перед камерою на невеликій відстані розташований уявний екран, що розділений на пікселі, кожен з якиї відповідає пікселю у вихідному зображенні. Із камери в бік сцени запускаються промені, кожен з яких проходить через піксель на уявному екрані. Для кожного з цих променів програма обчислює, чи перетинає він будь-який з трикутників, що розташовані на сцені. Якщо таких трикутників немає, то піксель фарбується в колір фону (чорний, наприклад). В інакшому випадку піксель фарбується іншим кольором. В найпростішому випадку — будь-яким відмінним від кольору фону. При цьому можуть враховуватися колір об\'єкта, кут падіння променя, затінення, глобальне освітлення і т.д. В цьому завданні ви маєте використати [flat shading](https://en.wikipedia.org/wiki/Shading#Flat_shading) або будь-яку складнішу модель затінення.

<img src="https://www.scratchapixel.com/images/upload/introduction-to-ray-tracing/lightingnoshadow.gif" width="250">

<img src="https://www.scratchapixel.com/images/upload/introduction-to-ray-tracing/pixelrender.gif" width="250">

*Зображення взяті з сайту www.scratchapixel.com*

Оскільки кількість трикутників може бути значною (зазвичай набагато більше за 1 млн), а швидкість найпростішого алгоритму складає O(n*m), де n — кількість трикутників, а m — кількість пікселів зображення, використовують структури даних схожі на дерева, що дозволяють швидко відсікати трикутники, які точно не перетинаються з променем під час трасування.

В даному варіанті ви маєте використати структуру octree або KD-tree або R-tree для оптимізації швидкості роботи трасування.

*Більш складний варіант (+1 бал):* додати трасування тіней: із кожної точки перед тим, як множити колір поверхні із кольором освітлення, переконайтесь, що між джерелом світла і точкою на поверхні немає інших предметів (трикутників). Для цього ви можете написати більш простий варіант пошуку перетину променя із деревом, який повертитиме будь-який трикутник, а не обов'язково найближчий.

### Приклад
Оскільки трасування променів доволі незрозуміла для багатьох тема, за [цим посиланням](https://repl.it/@L4fter/SpottedEnragedShell) ви можете знайти реалізацію саме трасування, результат якої виводиться в консоль.

Додавши затінення flat shading, освітлення та рух камери можна створити програму, що виводить в консоль зображення

![](examples_6/console_out.gif)

### Типові труднощі
Робота складна і в ній важко шукати причини помилок, які скоріш за все з'являться практично у всіх. Така поведінка притаманна справжнім (не навчальним) проектам, тому вам слід скористатися можливістю навчитися краще відлагоджувати код.
* Обов'язково переконайтися, що ваша програма корректно працює без дерева, перш ніж робити варіант із деревом. Якщо дерево вже є, зробіть зручний спосіб виконувати програму без нього. Так ви зможете розуміти, чи ваша конкретна помилка пов'язана із деревом.
* Не скидайте роботу по написанню дерева на одного члена команди: це найскладніша частина роботи і ви ризикуєте не вкластися у дедлайн, якщо залишите дерево наостанок.
* Під час пошуку перетину променя з усіма трикутниками вам треба шукати найближчий перетин (а не перший/останній, який трапиться під час обходу дерева). Вочевидь, це не стосується променів для трасування тіней.
* Майте можливість легко замінити колір фону. Якщо неосвітлені трикутники будуть чорного кольору і такого самого кольору буде фон, ви їх не зможете відрізнити. Це важливо, бо дає інформацію, чи перетнув промінь хоча б якийсь трикутник взагалі.
* Напрям нормалі трикутника залежить від послідовності обходу його точок (за годинниковою стрілкою чи проти). Це наслідок роботи векторного добутку. Переконайтеся, що всі трикутники задані в одному напрямі (як вказано в obj-файлі)
* Задавайте максимальну глибину дерева (тоді в одному листі дерева може бути кілька трикутників). Так ви зможете послідовно перевіряти, чи працює ваше дерево глибини 1, 2, 3 тощо. В деяких випадках проблеми виникають на межі двох гілок, і ви легше зможете зрозуміти в чому проблема.

Якщо у вас зображення виглядає не зовсім правильно, будь ласка, конкретно опишіть проблему, вкажіть, яке дерево ви використовуєте, як ви вже спробували вирішити проблему, чи є така проблема з іншою моделлю/без дерева/без освітлення/без тіней. Не кидайте просто зображення із підписом "хто знає в чому проблема?". 

### Посилання
* [Статті про трасування](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing/implementing-the-raytracing-algorithm), в яких дуже докладно описується, яким чином виконати цю лабораторну роботу, проте без використання дерев.
* [Формат obj](https://uk.wikipedia.org/wiki/Obj). Для цієї роботи треба вміти читати лише список вершин (v) та список граней (f), всі інші поля можна ігнорувати. Можливо, доречними будуть і нормалі.
* [Рендеринг](https://uk.wikipedia.org/wiki/%D0%A0%D0%B5%D0%BD%D0%B4%D0%B5%D1%80%D0%B8%D0%BD%D0%B3).
* [Octree](https://en.wikipedia.org/wiki/Octree).
* [KD-tree, R-tree](https://fat-crocodile.livejournal.com/156564.html).
* [Файли obj](https://github.com/coboshm/OpenGL-Samples/tree/master/Model) серед прикладів OpenGL.
