# **Unit 4: Navigation and app architecture**
Learn the best practices of app architecture to build more complex apps. Enhance your users' ability to navigate across, into and back out from the various screens within your app for a consistent and predictable user experience.

# Architecture Components
## Stages of the Activity lifecycle
![image](https://github.com/user-attachments/assets/be2dcc30-50b9-4b7f-ac39-5bab90052cb1)
(https://developer.android.com/codelabs/basic-android-kotlin-compose-activity-lifecycle)

- LogCat
- onCreate()
- onStart()
- onResume()
- activity stack
- finish()
- onDestory()
- app's visible lifecycle
- foreground lifetime
- focus vs visibility
- why you should keep the code in onPause() lightweight?
- A configuration change
### Lifecycle of a composable
- composition
- recomposition
- State
- MutableState
- remember()
- rememberSaveable()
---
```
var dessertsSold by rememberSaveable { mutableStateOf(0) }
var revenue by rememberSaveable { mutableStateOf(0) }

val currentDessertIndex by rememberSaveable { mutableStateOf(0) }

var currentDessertPrice by remember {
    mutableStateOf(desserts[currentDessertIndex].price)
}
var currentDessertImageId by remember {
    mutableStateOf(desserts[currentDessertIndex].imageId)
}
```
## Intro to App architecture
- ui layer, data layer
- UDF pattern
## Architecture: The UI Layer
- View Model, UI Elements
- event and state
## ViewModel and State in Compose
- App architecture
- 참고: https://developer.android.com/topic/architecture
- ViewModel
- OutlinedTextField
- AlertDialog
### Learn about app architecture
An app's architecture provides guidelines to help you allocate the app responsibilities between the classes. 
The most common architectural principles are separation of concerns and driving UI from a model.
- Separation of concerns
- Drive UI from a model
- Model

### Recommended app architecture
![image](https://github.com/user-attachments/assets/959dbc0c-259d-4b20-b1d3-ce6e7b139fff)
(https://developer.android.com/codelabs/basic-android-kotlin-compose-viewmodel-and-state)
여기서 화살표는 클래스의 의존성을 나타낸다.




