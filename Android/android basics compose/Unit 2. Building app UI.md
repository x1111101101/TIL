# Add a button to an app
## Create an interactive Dice Roller app
- Modifier#wrapContentSize
- remember()
- mutableStateOf()

src
``` kotlin

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            DiceRollerTheme {
                DiceRollerApp()
            }
        }
    }
}

@Preview(showSystemUi = true)
@Composable
fun DiceRollerApp() {
    DiceWithButtonAndImage(
        modifier = Modifier
            .fillMaxSize()
            .wrapContentSize(Alignment.Center)
    )
}


@Composable
fun DiceWithButtonAndImage(modifier: Modifier = Modifier) {
    var result by remember { mutableIntStateOf(1) }
    val imgResource = when(result) {
        1-> R.drawable.dice_1
        2-> R.drawable.dice_2
        3-> R.drawable.dice_3
        4-> R.drawable.dice_4
        5-> R.drawable.dice_5
        else-> R.drawable.dice_6
    }
    Column(modifier, horizontalAlignment = Alignment.CenterHorizontally) {
        Image(
            painter = painterResource(imgResource),
            contentDescription = result.toString()
        )
        Spacer(modifier = Modifier.height(16.dp))
        Button(onClick = { result = (1..6).random() }) {
            Text(stringResource(R.string.roll))
        }
    }
}
```
- 참고용: https://developer.android.com/develop/ui/compose/documentation?_gl=1*llf95a*_up*MQ..*_ga*MTg2MDU4NzQ2Ni4xNzE5OTk5NTMz*_ga_6HH9YJMN9M*MTcyMDAxMTIyMC4yLjAuMTcyMDAxMTIyMC4wLjAuMA..

## Use the debugger in Android Studio
There are two ways to run the debugger alongside your app:

Attach the debugger to an existing app process that runs on a device or emulator.
Run the app with the debugger.


## Practice: Click behavior
``` kotlin
data class Step(val name: String, val imageResource: Painter, val text: String)

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            Tutorial2Theme {
                App(Modifier.fillMaxSize())
            }
        }
    }
}


@Composable
@Preview(showSystemUi = true)
fun App(modifier: Modifier = Modifier) {
    val steps = arrayOf(
        Step("pickup", painterResource(id = R.drawable.lemon_tree), "Pickup"),
        Step("squeeze", painterResource(id = R.drawable.lemon_squeeze), "Squeeze"),
        Step("drink", painterResource(id = R.drawable.lemon_drink), "Drink"),
        Step("restart", painterResource(id = R.drawable.lemon_restart), "Restart")
    )
    var stepId by remember { mutableIntStateOf(0) }
    val step = steps[stepId]
    val onClick: ()->Unit = if(stepId == 1) {
        var left = (2..4).random();
        {
            if(--left == 0) {
                stepId++
            }
        }
    } else {
        {
            stepId = (stepId+1)%steps.size
        }
    }
    Panel(step = step, onClick,
        modifier
            .wrapContentSize()
    )
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun Panel(step: Step, onClick: ()->Unit, modifier: Modifier = Modifier) {
    Scaffold(
        modifier = modifier
            .fillMaxSize(),
        topBar = {
            CenterAlignedTopAppBar(
                title = {
                    Text(
                        text = "Lemonade",
                        fontWeight = FontWeight.Bold
                    )
                },
                colors = TopAppBarDefaults.largeTopAppBarColors(
                    containerColor = MaterialTheme.colorScheme.primaryContainer
                )
            )
        }
    ) { innerPadding->
        Surface(Modifier.padding(innerPadding)) {
            Column(modifier, horizontalAlignment = Alignment.CenterHorizontally) {
                Button(
                    colors = ButtonDefaults.buttonColors(containerColor = Color(50, 205, 50, 60)),
                    shape = RoundedCornerShape(28.dp),
                    modifier = Modifier,
                    onClick = onClick
                ) {
                    Image(painter = step.imageResource, contentDescription = step.name)
                }

                Text(text = step.text, fontSize = 18.sp, modifier = Modifier.padding(top = 20.dp))
            }
        }
    }
}
```

# Interact with UI and state
## Intro to state in Compose
- state
- Compose
- Composition
- Compose, Composition, Composable, State 들의 관계, Recomposition
- remember()
- state hoisting
- stateless composable
---
You should hoist the state when you need to:
- Share the state with multiple composable functions.
- Create a stateless composable that can be reused in your app.
---
- stringResource()
``` kotlin
class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        enableEdgeToEdge()
        super.onCreate(savedInstanceState)
        setContent {
            TipTimeTheme {
                Surface(
                    modifier = Modifier.fillMaxSize(),
                ) {
                    TipTimeLayout()
                }
            }
        }
    }
}

@Composable
fun EditNumberField(value: String, onValueChanged: (String)->Unit, modifier: Modifier = Modifier) {
    TextField(
        label = { Text(stringResource(R.string.bill_amount)) },
        singleLine = true,
        keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
        value = value,
        onValueChange = onValueChanged,
        modifier = modifier
    )
}

@Composable
fun TipTimeLayout() {
    var amountInput by remember { mutableStateOf("") }

    Column(
        modifier = Modifier
            .statusBarsPadding()
            .padding(horizontal = 40.dp)
            .safeDrawingPadding(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Text(
            text = stringResource(R.string.calculate_tip),
            modifier = Modifier
                .padding(bottom = 16.dp, top = 40.dp)
                .align(alignment = Alignment.Start)
        )
        EditNumberField(amountInput, { if(it.isEmpty() || it.toDoubleOrNull() != null) amountInput = it})
        Text(
            text = stringResource(R.string.tip_amount,
                calculateTip(amountInput.toDoubleOrNull() ?: 0.0)
            ),
            style = MaterialTheme.typography.displaySmall
        )
        Spacer(modifier = Modifier.height(150.dp))
    }
}

/**
 * Calculates the tip based on the user input and format the tip amount
 * according to the local currency.
 * Example would be "$10.00".
 */
private fun calculateTip(amount: Double, tipPercent: Double = 15.0): String {
    val tip = tipPercent / 100 * amount
    return NumberFormat.getCurrencyInstance().format(tip)
}

@Preview(showBackground = true)
@Composable
fun TipTimeLayoutPreview() {
    TipTimeTheme {
        TipTimeLayout()
    }
}
```

## Calculate a custom tip
- @StringRes
- @DrawableRes
- KeyboardOption
- keyboard action
- portrait and landscape
- scroll

## Write automated tests
- what is testing for software
- automated testing
why automated testing is required:
- ensure functionalities
- cost in manual testing
- different type of devices
---
- local test
- instrumentation test
- test apk
### Write a local test
- @VisibleForTesting
- nsure that the name clearly describes what the test tests for and what the expected result is.
- assert
### Write an instrumentation test
- androidTest directory
- composableTestRule
```
package com.example.tiptime

import androidx.compose.ui.test.junit4.createComposeRule
import androidx.compose.ui.test.onNodeWithText
import androidx.compose.ui.test.performTextClearance
import androidx.compose.ui.test.performTextInput
import com.example.tiptime.ui.theme.TipTimeTheme
import org.junit.Rule
import org.junit.Test
import java.text.NumberFormat

class TipUITests {

    @get:Rule
    val composeTestRule = createComposeRule()

    @Test
    fun calculate_20_percent_tip() {
        composeTestRule.setContent {
            TipTimeTheme {
                TipTimeLayout()
            }
        }

        composeTestRule.onNodeWithText("Bill Amount").apply {
            performTextClearance()
            performTextInput("10")
        }

        composeTestRule.onNodeWithText("Tip Percentage").apply {
            performTextClearance()
            performTextInput("20")
        }

        val expectedTip = NumberFormat.getCurrencyInstance().format(2)
        composeTestRule.onNodeWithText("Tip Amount: $expectedTip", true)
            .assertExists()
    }

}
```
## Create an Art Space app
- https://m3.material.io/foundations/layout/understanding-layout/overview
Use your prototype to help translate your design into code:
- Identify UI elements needed to build your app.
- Identify different logical sections of the apps and draw boundaries around them.
---
- https://developer.android.com/develop/ui/compose/layouts/adaptive/support-different-screen-sizes
``` kotlin
class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            App()
        }
    }
}

data class ArtworkDescription(val title: String, val year: String, val artist: String)
data class Artwork(@DrawableRes val image: Int, val description: ArtworkDescription)
val ARTWORKS = listOf(
    Artwork(
        R.drawable.cat_8612685_1280,
        ArtworkDescription("Cat", "2024", "Artist1")
    ),
    Artwork(
        R.drawable.cookies_8668140_1280,
        ArtworkDescription("Cookies", "2023", "baker")
    )
)

@Preview(showSystemUi = true)
@Composable
fun App(modifier: Modifier = Modifier) {
    var artworkId by remember { mutableIntStateOf(0) }
    val artwork = ARTWORKS[artworkId]
    val description = artwork.description
    Tutorial3Theme {
        Scaffold(modifier= Modifier
            .fillMaxSize()) { innerPadding->
            Column(
                modifier = Modifier
                    .fillMaxSize()
                    .padding(innerPadding)
                    .verticalScroll(rememberScrollState()),
                horizontalAlignment = Alignment.CenterHorizontally,
                verticalArrangement = Arrangement.SpaceEvenly
            ) {
                Artwork(resource = artwork.image,
                    modifier = Modifier
                        .weight(0.45f)
                        .fillMaxWidth(0.9f)
                )
                Spacer(modifier = Modifier.weight(0.05f))
                Informations(
                    ArtworkDescription(description.title, description.year, description.artist),
                    Modifier
                        .fillMaxWidth(0.8f)
                        .weight(0.1f)
                        .background(Color.LightGray)
                )
                Spacer(modifier = Modifier.weight(0.05f))
                Controls(
                    prev = {
                        artworkId = (artworkId + ARTWORKS.size-1) % ARTWORKS.size
                    },
                    next = {
                        artworkId = (artworkId + 1) % ARTWORKS.size
                    },
                    Modifier
                        .fillMaxWidth(0.8f)
                        .height(52.dp)
                        .padding(bottom = 12.dp)
                )
            }
        }

    }
}

@Composable
fun Artwork(@DrawableRes resource: Int, modifier: Modifier = Modifier) {
    val painter = painterResource(id = resource)
    Surface(
        modifier=modifier
        ,
        shadowElevation = 16.dp
    ) {
        Image(painter = painter, contentDescription = "artwork", Modifier.padding(20.dp))
    }

}

@Composable
fun Informations(description: ArtworkDescription, modifier: Modifier = Modifier) {
    Column(
        modifier,
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Text(text = description.title)
        Row(horizontalArrangement = Arrangement.SpaceBetween) {
            Text(text = description.artist)
            Text(text = "(${description.year})")
        }
    }
}

@Composable
fun Controls(prev: ()->Unit, next: ()->Unit, modifier: Modifier = Modifier) {
    @Composable
    fun ButtonText(text: String) {
        Text(text = text)
    }
    Row(modifier, horizontalArrangement = Arrangement.SpaceEvenly) {
        Button(
            modifier = Modifier.weight(0.3f),
            onClick = prev
        ) {
            ButtonText(text = "Previous")
        }
        Spacer(modifier = Modifier.weight(0.2f))
        Button(
            modifier = Modifier.weight(0.3f),
            onClick = next
        ) {
            ButtonText(text = "Next")
        }
    }
}
```
