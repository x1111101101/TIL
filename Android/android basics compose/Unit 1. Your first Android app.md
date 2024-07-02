# Build a basic layout
## 3. Build a simple app with text composables
- @Composable
- @Preview
- dp, sp
- arrangement of Composables
- Trailing Lambda Syntax
- Column, Row, Box
## 4. Add images to your Android app
- Android Studio Resource Manager
- drawable-nodpi
- painterResource()
- Box layout
- contentScale
- Row: horizontalArrangement and verticalAlignment
- Column: verticalArrangement and horizontalAlignment
- Android Studio feature - Extract Resource
- String resources - strings.xml

``` kotlin
package io.github.x1111101101.tutorial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import io.github.x1111101101.tutorial.ui.theme.TutorialTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            TutorialTheme {
                Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colorScheme.background) {
                    GreetingImage(
                        message = stringResource(R.string.happy_birthday_text),
                        from = stringResource(R.string.signature_text),
                        modifier = Modifier.padding(8.dp)
                    )
                }
            }
        }
    }
}

@Composable
private fun GreetingImage(message: String, from: String, modifier: Modifier=Modifier) {
    val image = painterResource(R.drawable.androidparty)
    Box(modifier) {
        Image(
            painter = image,
            contentDescription = null,
            contentScale = ContentScale.Crop,
            alpha = 0.5F
        )
        GreetingText(
            message = message,
            from = from,
            modifier = Modifier
                .fillMaxSize()
                .padding(8.dp)
        )
    }

}

@Composable
private fun GreetingText(message: String, from: String, modifier: Modifier = Modifier) {
    Column(
        verticalArrangement = Arrangement.Center,
        modifier = modifier
            .padding(8.dp)
    ) {
        Text(
            text = message,
            fontSize = 100.sp,
            lineHeight = 116.sp,
            textAlign = TextAlign.Center
        )
        Text(
            text = from,
            fontSize = 36.sp,
            modifier = Modifier
                .padding(16.dp)
                .align(Alignment.CenterHorizontally)
        )
    }

}

@Preview(showBackground = true, showSystemUi = true)
@Composable
fun BirthDayCardPreview() {
    TutorialTheme {
        GreetingImage(message = "Happy Birthday Sam!", from="From ABC")
    }
}
```


## 5. Practice: Compose Basics
Compose article
``` kotlin
package io.github.x1111101101.tutorial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.TextUnit
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import io.github.x1111101101.tutorial.ui.theme.TutorialTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            App()
        }
    }
}

@Composable
fun App(modifier: Modifier = Modifier) {
    TutorialTheme {
        Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colorScheme.background) {
            Column(modifier) {
                TopImage()
                ArticleText(stringResource(R.string.article_title), 24.sp)
                ArticleText(stringResource(R.string.article_middle))
                ArticleText(stringResource(R.string.article_bottom))
            }
        }
    }
}

@Composable
fun ArticleText(content: String, fontSize: TextUnit = TextUnit.Unspecified) {
    Text(
        text = content,
        fontSize = fontSize,
        modifier = Modifier.padding(16.dp)
    )
}

@Composable
fun TopImage(modifier: Modifier = Modifier) {
    val painter = painterResource(id = R.drawable.bg_compose_background)
    Image(painter = painter, contentDescription = null, contentScale = ContentScale.FillWidth)
}


@Preview(showBackground = true, showSystemUi = true)
@Composable
fun Preview() {
    App()
}
```

Task manager
``` kotlin
package io.github.x1111101101.tutorial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import io.github.x1111101101.tutorial.ui.theme.TutorialTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            App()
        }
    }
}

@Composable
fun App(modifier: Modifier = Modifier) {
    TutorialTheme {
        Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colorScheme.background) {
            Column(verticalArrangement = Arrangement.Center, horizontalAlignment = Alignment.CenterHorizontally) {
                Icon()
                Text(
                    text = "All tasks completed",
                    fontWeight = FontWeight.Bold,
                    modifier = Modifier.padding(top=24.dp, bottom = 8.dp)
                )
                Text(
                    text = "Nice work!",
                    fontSize = 16.sp,
                )
            }
        }
    }
}

@Composable
fun Icon(modifier: Modifier = Modifier) {
    val painter = painterResource(id = R.drawable.ic_task_completed)
    Image(painter = painter, contentDescription = null, contentScale = ContentScale.FillWidth, modifier = modifier)
}


@Preview(showBackground = true, showSystemUi = true)
@Composable
fun Preview() {
    App()
}
```

Quadrant
``` kotlin
package io.github.x1111101101.tutorial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import io.github.x1111101101.tutorial.ui.theme.TutorialTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            App()
        }
    }
}

@Composable
fun App(modifier: Modifier = Modifier) {
    TutorialTheme {

        Surface(modifier = modifier, color = MaterialTheme.colorScheme.background) {
            Column(verticalArrangement = Arrangement.Center, horizontalAlignment = Alignment.CenterHorizontally) {
                QuadrantRow(Modifier.fillMaxHeight(0.5f))
                {
                    Quadrant(title = "TEST", content = "TEST",
                        Modifier
                            .fillMaxWidth(0.5f)
                            .background(Color(0xFFEADDFF))
                    )
                    Quadrant(title = "TEST2", content = "TEST",
                        Modifier
                            .fillMaxWidth()
                            .background(Color(0xFFD0BCFF))
                    )
                }
                QuadrantRow {
                    Quadrant(title = "TEST3", content = "TEST",
                        Modifier
                            .fillMaxWidth(0.5f)
                            .background(Color(0xFFB69DF8))
                    )
                    Quadrant(title = "TEST4", content = "TEST",
                        Modifier
                            .fillMaxWidth()
                            .background(Color(0xFFF6EDFF))
                    )
                }
            }
        }
    }
}

@Composable
fun QuadrantRow(modifier: Modifier = Modifier, children: @Composable ()->Unit) {
    Row(modifier) {
        children()
    }
}


@Composable
fun Quadrant(title: String, content: String, modifier: Modifier = Modifier) {
    Column(
        modifier
            .fillMaxHeight(1f)
            .padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(text = title, fontWeight = FontWeight.Bold, modifier = Modifier.padding(bottom = 16.dp))
        Text(text = content, textAlign = TextAlign.Justify)
    }
}

@Preview(showBackground = true, showSystemUi = true)
@Composable
fun Preview() {
    App()
}
```

