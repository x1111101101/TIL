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
