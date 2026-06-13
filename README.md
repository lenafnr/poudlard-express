# Poudlard_Express_Léna-Romane

# Organisation des fichiers
```
├── .vscode/
│   ├── json.hpp
│   └── settings.json
├── assets/
│   ├── shaders/
│   └── textures/ : contient les textures de la SkyBox et des objets
├── data/
│   ├── oldsrails.json : JSON donné en consignes, non utilisé
│   └── props.json : notre JSON (placement des rails, gare, train, arbres et lampadaires)
├── third_party/ : les bibliothèques
│   ├── glad/
│   ├── glbasimac/
│   └── glfw/
├── train/
│   ├── CMakeLists.txt
│   ├── draw_scene.cpp
│   ├── draw_scene.hpp
│   ├── drawSky.cpp : la SkyBox
│   ├── drawSky.hpp
│   ├── json_manager.cpp
│   ├── json_manager.hpp
│   ├── json.hpp
│   ├── light_manager.cpp
│   ├── light_manager.hpp
│   ├── main.cpp
│   ├── objects.cpp : définition et initialisation de nos objets 2D (arc de cercle, cercle) et 3D
│   ├── objects.hpp
│   ├── rails.cpp
│   ├── rails.hpp
│   ├── station.cpp
│   ├── station.hpp
│   ├── texture_manager.cpp
│   ├── texture_manager.hpp
│   ├── train.cpp
│   ├── train.hpp
│   ├── trees.cpp
│   └── trees.hpp
├── .gitignore
├── CMakeLists.txt
└── README.md
```