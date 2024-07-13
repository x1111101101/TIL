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
The UI layer is made up of the following components:
- UI elements
- State holders
---
The UI is the visual representation of the UI state.
``` kotlin
// Example of UI state definition

data class NewsItemUiState(
    val title: String,
    val body: String,
    val bookmarked: Boolean = false,
    ...
)
```
you should never modify the UI state in the UI directly, unless the UI itself is the sole source of its data.
Violating this principle results in multiple sources of truth for the same piece of information, leading to data inconsistencies and subtle bugs.
- StateFlow
- MutableStateFlow
- backing property
    - ``` kotlin
        class GameViewModel : ViewModel() {
        
            private val _uiState = MutableStateFlow(GameUiState())
            val uiState: StateFlow<GameUiState> = _uiState.asStateFlow()
        
        }
        ```

### Architecting your Compose UI
In Compose, the only way to update the UI is by changing the state of the app. What you can control is your UI state. Every time the state of the UI changes, Compose recreates the parts of the UI tree that changed.
- Composable's two UDF pattern behavior
![image](https://github.com/user-attachments/assets/6df7cc1e-fab1-40ab-bbb2-0aeff89c7d60)
(https://developer.android.com/codelabs/basic-android-kotlin-compose-viewmodel-and-state)
The use of the UDF pattern for app architecture has the following implications:
```
The ViewModel holds and exposes the state the UI consumes.
The UI state is application data transformed by the ViewModel.
The UI notifies the ViewModel of user events.
The ViewModel handles the user actions and updates the state.
The updated state is fed back to the UI to render.
This process repeats for any event that causes a mutation of state.
```
- viewModel()
- collectAsState()
- MutableStateFlow<T>.update

