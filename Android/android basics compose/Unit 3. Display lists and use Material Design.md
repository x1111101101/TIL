# Build a scrollable list
- data class
- card
- LazyColumn
- items() in LazyListScope
``` kotlin
class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            AffirmationsTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    AffirmationsApp()
                }
            }
        }
    }
}



@Composable
@Preview
fun AffirmationsApp(modifier: Modifier = Modifier) {
    val layoutDirection = LocalLayoutDirection.current
    val sources = Datasource().loadAffirmations()
    Surface(
        modifier = modifier
            .fillMaxSize()
            .statusBarsPadding()
            .padding(
                start = WindowInsets.safeDrawing
                    .asPaddingValues()
                    .calculateStartPadding(layoutDirection),
                end = WindowInsets.safeDrawing
                    .asPaddingValues()
                    .calculateEndPadding(layoutDirection),
            ),
    ) {
        AffirmationList(list = sources)
    }

}

@Composable
fun AffirmationList(list: List<Affirmation>, modifier: Modifier = Modifier) {
    LazyColumn(modifier) {
        items(items=list) { item->
            Log.w("", "load: $item")
            AffirmationCard(affirmation = item, Modifier.padding(8.dp))
        }
    }
}

@Composable
fun AffirmationCard(affirmation: Affirmation, modifier: Modifier = Modifier) {
    Card(modifier) {
        Column {
            Image(
                painter = painterResource(id = affirmation.imageResourceId),
                contentDescription = null,
                contentScale = ContentScale.Crop,
                modifier = Modifier
                    .height(194.dp)
                    .fillMaxWidth()
            )
            Text(
                text = stringResource(id = affirmation.stringResourceId),
                style = MaterialTheme.typography.headlineSmall,
                modifier = Modifier.padding(16.dp)
            )
        }
    }
}
```
## Change the app icon
- launcher icon
- adaptive icons 
- Image Asset Studio
- screen density
- mipmap folder
- density qualifier
- Note that device screen densities won't be precisely 160 dpi, 240 dpi, 320 dpi, etc. Based on the device's screen density, Android selects the resource at the closest larger density bucket and then scales it down.
- adaptive icon - foreground, background, mask
- mipmap-anydpi-v26
- bitmap vs vector: The advantage is that a vector graphic can be scaled for any canvas size, for any screen density, without losing quality.
- 참고: https://developer.android.com/reference/kotlin/android/graphics/drawable/AdaptiveIconDrawable
- safe zone
- backwards compatibility
- legacy launcher icons
- Image Asset Studio
- 
